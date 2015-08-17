#include <gtk_gui_manager.h>

#include <gtkmm/messagedialog.h>
#include <gtkmm/enums.h>
#include <gtkmm/window.h>

#include <string>
#include <memory>
#include <chrono>
#include <stdexcept>

#include <i_main_window_presenter.h>
#include <i_gui_object.h>
#include <i_view.h>
#include <i_view_window.h>

#include <main_window_presenter.h>
#include <gtk_main_window.h>
#include <gtk_window.h>
#include <gtk_logger.h>
#include <view_preferences_manager.h>
#include <gtk_view_container.h>
#include <view_preferences_loader.h>
#include <gtk_view_window.h>
#include <view_window_presenter.h>
#include <gtk_window_factory.h>
#include <invalid_parent.h>

INIT_LOCATION;

namespace erebus {

const std::string  GTK_GUIManager::STD_APP_ID="org.werner.erebus";


GTK_GUIManager::GTK_GUIManager():viewPreferences_(std::make_unique<ViewPreferencesManager>()) {
	LOG_GTK(normal)<<"Constructing the gui manager";

	isInitialized_=false;
}

GTK_GUIManager::~GTK_GUIManager() {
	LOG_GTK(normal)<<"Destructing the gui manager";

	//Even though this seems to be redundant since the vector and its elements
	//get automatically destroyed during destruction it isnt.
	//This is necessary to allow the children of the windows and the windows itsel to
	//refer to the gui manager.
	//Otherwise a destroyed gui manager would be dereferenced -> really bad.
	while(!windows_.empty()) {
		windows_.pop_back();
	}
}

void GTK_GUIManager::showMessageDialog(std::string primaryText,std::string secondaryText,
                                       ErrorLevel errorLevel) {
	LOG_ASSERT_GTK(isInitialized_);
	LOG_ASSERT_GTK(dummyWindow_.get()!=nullptr);

	showMessageDialogPr(*(dummyWindow_.get()),primaryText,secondaryText,errorLevel);
}

void GTK_GUIManager::showMessageDialog(std::size_t id,std::string primaryText,
                                       std::string secondaryText,
                                       ErrorLevel errorLevel) {
	LOG_ASSERT_GTK(isInitialized_);

	Gtk::Window* window=getWindow(id);
	if(window==nullptr) {
		LOG_GTK(warning)<<"Could not find widget.";

		window=dummyWindow_.get();
	}
	showMessageDialogPr(*window,primaryText,secondaryText,errorLevel);
}

void GTK_GUIManager::loadCustomViewPreferences() {
	viewPreferences_=ViewPreferencesLoader::loadCustomViewPreferences(std::move(viewPreferences_));
}

void GTK_GUIManager::loadDefaultViewPreferences() {
	viewPreferences_=ViewPreferencesLoader::loadDefaultViewPreferences(std::move(viewPreferences_));
}

GTK_Window* GTK_GUIManager::getWindow(std::size_t id) {
	LOG_ASSERT_GTK(isInitialized_);

	for(auto& window:windows_) {
		if(window->containsWidget(id)) {
			auto c_window=dynamic_cast<GTK_Window*>(window.get());
			if(c_window==0) {
				return nullptr;
			}
			return c_window;
		}
	}
	return nullptr;
}

void GTK_GUIManager::closeEmptyViewWindows() {
	auto i = std::begin(windows_);

	while (i != std::end(windows_)) {
		if((*i)->classname()==GTK_ViewWindow::CLASSNAME) {
			auto view_window=dynamic_cast<GTK_ViewWindow*>((*i).get());
			if(view_window!=0) {
				if (view_window->isEmpty()) {
					LOG_GTK(normal)<<view_window->getID();
					view_window->Gtk::Window::close();
					windows_.erase(i);
					continue;
				}
			} else {
				LOG_GTK(error)<<"Cast failed!";
			}
		}
		++i;
	}
}

void GTK_GUIManager::showMessageDialogPr(Gtk::Window& window,std::string primaryText,
        std::string secondaryText,
        ErrorLevel errorLevel) {
	LOG_ASSERT_GTK(isInitialized_);

	Gtk::MessageType type=Gtk::MESSAGE_INFO;

	switch(errorLevel) {
	case ErrorLevel::INFO:
		type=Gtk::MESSAGE_INFO;
		break;
	case ErrorLevel::WARNING:
		type=Gtk::MESSAGE_WARNING;
		break;
	case ErrorLevel::ERROR:
		type=Gtk::MESSAGE_ERROR;
		break;
	default:
		LOG_ASSERT_GTK(false);
		break;
	};

	Gtk::MessageDialog dialog(window,primaryText,type);
	dialog.set_secondary_text(secondaryText);

	dialog.run();
}

void GTK_GUIManager::resetViewPreferences() {
	viewPreferences_=std::make_unique<ViewPreferencesManager>();
}

void GTK_GUIManager::joinContainer(std::size_t id) {
	LOG_ASSERT_GTK(isInitialized_);

	IGUIObject* parent=nullptr;
	try {
		parent=getParentOf(id);
	} catch(const invalid_parent& e) {
		LOG_GTK(error)
		        <<"Cannot join container due to a widget '"<<id<<"' having more tha one parent ("<<e.what()<<")";
		showMessageDialog(id,"Cannot join the container!",
		                  std::string("There has been a problem with the object hierachy. (")+e.what()+")",ErrorLevel::ERROR);
	}

	if(parent==nullptr) {
		LOG_GTK(warning)<<"'"<<id<<"' was not found. There is most likely a bug somwhere in the code.";
		return;
	}

	if(parent->classname()==GTK_ViewContainer::CLASSNAME) {
		auto viewcontainer=dynamic_cast<GTK_ViewContainer*>(parent);
		if(viewcontainer==0) {
			LOG_GTK(error)<<"Cast failed! Cant join the container '"<<parent->getID()<<"'";
			showMessageDialog(id,"Cannot join the container!","There has been a cast failure.",
			                  ErrorLevel::ERROR);
			return;
		}
		viewcontainer->join();
	}
}

IGUIObject* GTK_GUIManager::getParentOf(std::size_t id) {
	LOG_ASSERT_GTK(isInitialized_);

	IGUIObject* parent=nullptr;
	for(auto& window:windows_) {
		auto buff=window->getParentOf(id);
		if(buff!=nullptr) {
			if(parent==nullptr) {
				parent=buff;
			} else {
				throw invalid_parent(std::string("'")+std::to_string(id)+"' has more than one parent!");
			}
		}
	}
	return parent;
}

void GTK_GUIManager::initialize(int argc, char** argv) {
	LOG_ASSERT_GTK(!isInitialized_);

	//Allow multiple instances of the appliation by adding the time to the application id
	std::string id=STD_APP_ID;

	//if(viewPreferences_->getBooleanPreference(AllowMultipleApplicationInstancesPref::KEY)) {
	id+=std::to_string(std::chrono::duration_cast<std::chrono::milliseconds>
	                   (std::chrono::system_clock::now().time_since_epoch()).count());
	//}

	application_=Gtk::Application::create(argc, argv,id);

	dummyWindow_=std::make_unique<Gtk::Window>();

	isInitialized_=true;
}

IViewWindow& GTK_GUIManager::createNewViewWindow() {
	LOG_ASSERT_GTK(isInitialized_);

	auto viewWindow=GTK_WindowFactory::createWindow<GTK_ViewWindow,ViewWindowPresenter>(*this,
	                WindowType::VIEW_WINDOW);
	viewWindow->show();
	auto& window=addWindow(std::move(viewWindow),false);

	//This cast is safe since it gets just casted from
	//dervied to base back to the same derived class.
	return dynamic_cast<GTK_ViewWindow&>(window);
}

void GTK_GUIManager::runGUI() {
	LOG_ASSERT_GTK(isInitialized_);

	auto window=GTK_WindowFactory::createWindow<GTK_MainWindow,MainWindowPresenter>(*this,
	            WindowType::MAIN_WINDOW);

	window->setPreferredSize(800,600);
	window->maximize();

	try {
		auto& ir_window=addWindow(std::move(window),false);
		auto& r_window=dynamic_cast<GTK_Window&>(ir_window);
		application_->run(r_window);
	} catch(const std::bad_cast& e) {
		LOG_GTK(error)<<"Cast failed";
		throw;
	}

}

ViewPreferencesManager& GTK_GUIManager::getViewPreferences() {
	return *viewPreferences_.get();
}

IWindow& GTK_GUIManager::addWindow(std::unique_ptr<IWindow> window,bool makePersistent) {
	LOG_ASSERT_GTK(window.get()!=nullptr);
	LOG_ASSERT_GTK(isInitialized_);

	windows_.push_back(std::move(window));

	//we put it in and then get it back out since window gets moved and is nullptr at this point.
	auto v_window=(windows_.back()).get();

	if(makePersistent) {
		auto c_window=dynamic_cast<GTK_Window*>(v_window);

		if(c_window==0) {
			LOG_GTK(error)<<"Could not make "<<c_window->classname()
			              <<" '"<<c_window->getID()<<"' persistent";
		} else {
			application_->add_window(*c_window);
		}
	}

	return *(v_window);
}

void GTK_GUIManager::destroyWindow(IWindow& window) {
	LOG_ASSERT(gtk_l::get(),isInitialized_);

	try {
		auto rwindows=std::remove_if(windows_.begin(), windows_.end(),
		[&window](const std::unique_ptr<IWindow>& iwindow) {
			return iwindow.get()->getID()==window.getID();
		});

		if(rwindows!=windows_.end()) {
			windows_.erase(rwindows,windows_.end());
		}
	} catch(const std::exception& e) {
		LOG_GTK(warning)<<"Could not destroy "<<window.classname()<<" '"<<window.getID()
		                <<"' ("<<e.what()
		                <<"). It will be destroyed when closing the application";
	}
}

void GTK_GUIManager::moveViewToNewWindow(IView& view) {
	LOG_ASSERT_GTK(isInitialized_);

	auto& window=createNewViewWindow();
	LOG_GTK(normal)<<"Moving "<<view.classname()<<" '"<<view.getID()<<"' to "<<window.classname()
	               <<" '"<<window.getID()<<"'";
	window.addView(view);
}

}//namespace erebus

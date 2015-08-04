#include <gtk_gui_manager.h>

#include <gtkmm/messagedialog.h>
#include <gtkmm/enums.h>
#include <gtkmm/window.h>

#include <string>
#include <memory>
#include <stdexcept>

#include <presenter/interfaces/i_main_window_presenter.h>

#include <glade_files.h>
#include <presenter/main_window_presenter.h>
#include <gtk_main_window.h>
#include <gtk_logger.h>
#include <gtk_window_factory.h>

INIT_LOCATION;

namespace erebus {

const std::string  GTK_GUIManager::PACKAGE_NAME="org.werner.erebus";


GTK_GUIManager::GTK_GUIManager() {
	BOOST_LOG_SEV(gtk_l::get(),normal)<<LOCATION<<"Constructing gui manager '"<<getID()<<"'";

	isInitialized_=false;
}

GTK_GUIManager::~GTK_GUIManager() {
	BOOST_LOG_SEV(gtk_l::get(),normal)<<LOCATION<<"Destructing gui manager '"<<getID()<<"'";
}

void GTK_GUIManager::showMessageDialog(std::string primaryText,std::string secondaryText,
                                       ErrorLevel errorLevel) {
	showMessageDialogPr(*(dummyWindow_.get()),primaryText,secondaryText,errorLevel);
}

void GTK_GUIManager::showMessageDialog(IWindow& window,std::string primaryText,
                                       std::string secondaryText,
                                       ErrorLevel errorLevel) {
	try {
		auto& c_window=dynamic_cast<Gtk::Window&>(window);
		showMessageDialogPr(c_window,primaryText,secondaryText,errorLevel);
	} catch(const std::bad_cast& e) {
		BOOST_LOG_SEV(gtk_l::get(),warning)
		        <<LOCATION<<"Could not show MessageDialog :"<<primaryText<<":"
		        <<secondaryText<<"["<<static_cast<int>(errorLevel)<<"]";
	}
}

void GTK_GUIManager::showMessageDialogPr(Gtk::Window& window,std::string primaryText,
        std::string secondaryText,
        ErrorLevel errorLevel) {
	Gtk::MessageType type=Gtk::MESSAGE_INFO;

	switch(errorLevel) {
	case ErrorLevel::INFO:
		type=Gtk::MESSAGE_INFO;
		break;
	case ErrorLevel::ERROR:
		type=Gtk::MESSAGE_ERROR;
		break;
	default:
		type=Gtk::MESSAGE_OTHER;
		break;
	};

	Gtk::MessageDialog dialog(window,primaryText,false,type,Gtk::BUTTONS_OK,true);
	dialog.set_secondary_text(secondaryText);

	dialog.run();
}

void GTK_GUIManager::initialize(int argc, char** argv) {
	LOG_ASSERT(gtk_l::get(),!isInitialized_);

	application_=Gtk::Application::create(argc, argv,PACKAGE_NAME);

	dummyWindow_=std::make_unique<Gtk::Window>();

	isInitialized_=true;
}

long GTK_GUIManager::getID() {
	return reinterpret_cast<long>(this);
}

void GTK_GUIManager::runGUI() {
	LOG_ASSERT(gtk_l::get(),isInitialized_);

	auto window=GTK_WindowFactory::createMainWindow(*this);

	window->setPreferredSize(800,600);
	window->maximize();

	try {
		auto& ir_window=addWindow(std::move(window),false);
		auto& r_window=dynamic_cast<GTK_Window&>(ir_window);
		application_->run(r_window);
	} catch(const std::bad_cast& e) {
		BOOST_LOG_SEV(gtk_l::get(),error)<<LOCATION<<"Cast failed";
		throw;
	}

}

IWindow& GTK_GUIManager::addWindow(std::unique_ptr<IWindow> window,bool makePersistent) {
	LOG_ASSERT(gtk_l::get(),window.get()!=nullptr);
	LOG_ASSERT(gtk_l::get(),isInitialized_);

	windows_.push_back(std::move(window));

	auto v_window=(windows_.back()).get();

	if(makePersistent) {
		auto c_window=dynamic_cast<GTK_Window*>(v_window);

		if(c_window==0) {
			BOOST_LOG_SEV(gtk_l::get(),error)<<LOCATION<<"Could not make "<<c_window->classname()
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
		BOOST_LOG_SEV(gtk_l::get(),warning)<<"Could not destroy "<<window.classname()<<" '"<<window.getID()
		                                   <<"' ("<<e.what()<<"). It will be destroyed when closing the application";
	}
}
/*
void GUIManager::moveViewToNewWindow(IView& view) {
	auto builder=GTK_BuilderFactory::getBuilder(Windows::VIEW_WINDOW);

	GTK_ViewWindow* viewWindow;
	builder->get_widget_derived("view_window", viewWindow);

	auto presenter=std::unique_ptr<IViewWindowPresenter>(
	                   std::make_unique<ViewWindowPresenter>());

	presenter->setWindow(viewWindow);

	viewWindow->setPresenter(std::move(presenter));

	BOOST_LOG_SEV(gtk_l::get(),normal)
		<<LOCATION<<"Moving view '"<<&view<<"' to a new view window '"<<viewWindow<<"'";
	viewWindow->getBasicViewContainer().addView(view);

	viewWindow->show();

	windows_.push_back(std::unique_ptr<IWindow>(viewWindow));
}
*/
}//namespace erebus

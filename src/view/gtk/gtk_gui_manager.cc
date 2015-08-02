#include <gtk_gui_manager.h>

#include <gtkmm/messagedialog.h>
#include <gtkmm/enums.h>

#include <string>
#include <assert.h>

#include <presenter/interfaces/i_main_window_presenter.h>

#include <glade_files.h>
#include <presenter/main_window_presenter.h>
#include <gtk_main_window.h>
#include <gtk_builder_factory.h>
#include <logger.h>

INIT_LOCATION;

namespace erebus {

const std::string  GTK_GUIManager::PACKAGE_NAME="org.werner.erebus";


GTK_GUIManager::GTK_GUIManager() {
	isInitialized_=false;
}

GTK_GUIManager::~GTK_GUIManager() {

}

void GTK_GUIManager::showMessageDialog(std::string primaryText,std::string secondaryText,
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

	Gtk::MessageDialog dialog(primaryText,false,type,Gtk::BUTTONS_OK,true);
	dialog.set_secondary_text(secondaryText);

	dialog.run();
}

void GTK_GUIManager::initialize(int argc, char** argv) {
	application_=Gtk::Application::create(argc, argv,PACKAGE_NAME);

	isInitialized_=true;
}

void GTK_GUIManager::runGUI() {
	assert(isInitialized_);

	auto builder=GTK_BuilderFactory::getBuilder(Windows::MAIN_WINDOW);

	GTK_MainWindow* window;
	builder->get_widget_derived("main_window", window);

	auto presenter=std::unique_ptr<IMainWindowPresenter>(std::make_unique<MainWindowPresenter>());
	presenter->setWindow(window);

	window->setPresenter(std::move(presenter));

	window->setPreferredSize(800,600);
	window->maximize();

	application_->run(*window);
}

/*void GUIManager::addWindow(IWindow& window) {
	auto& guido=GTK_GUIStateObject::getState(*stateObject_.get());

	try {
		auto& window_c=dynamic_cast<GTK_Window&>(window);
		guido.application_->add_window(window_c);
	} catch(std::bad_cast e) {
		BOOST_LOG_SEV(gtk_l::get(),warning)<<LOCATION<<"Cast failed.";
		return;
	}
}

void GUIManager::deleteWindow(IWindow* window) {
	if(window==nullptr)
		return;

	auto rwindows=std::remove_if(windows_.begin(), windows_.end(),
	[window](const std::unique_ptr<IWindow>& iwindow) {
		return iwindow.get()==window;
	});

	if(rwindows!=windows_.end()) {
		windows_.erase(rwindows,windows_.end());
		window=nullptr;
	}

}

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

void GUIManager::showInfoDialog(std::string title,std::string text,ErrorLevel el) {
	auto& guido=GTK_GUIStateObject::getState(*stateObject_.get());

	std::unique_ptr<Gtk::MessageDialog> dialog;
	switch(el) {
		case ErrorLevel::INFO:
			dialog=std::make_unique<MessageDialog>(*guido.mainWindow_, title);
			break;
		case ErrorLevel::ERROR:
			dialog=std::make_unique<MessageDialog>(*guido.mainWindow_, title,Gtk::ERROR);
			break;
		default:
			assert(false);
			break;
	}
	dialog->set_secondary_text(text);
	dialog->run();
}*/

}//namespace erebus

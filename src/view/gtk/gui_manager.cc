#include <view/gui_manager.h>

#include <gtkmm.h>

#include <memory>
#include <typeinfo>

#include <presenter/interfaces/i_main_window_presenter.h>
#include <view/interfaces/i_main_window.h>
#include <view/interfaces/i_view.h>
#include <view/interfaces/i_window.h>
#include <presenter/interfaces/i_view_window_presenter.h>

#include <gtk_builder_factory.h>
#include <gtk_main_window.h>
#include <gtk_gui_state_object.h>
#include <gtk_window.h>
#include <gtk_view_window.h>
#include <gtk_logger.h>
#include <presenter/main_window_presenter.h>
#include <presenter/view_window_presenter.h>
#include <glade_files.h>


namespace erebus {

std::unique_ptr<GUIManager> GUIManager::guiManager_=std::unique_ptr<GUIManager>(nullptr);


GUIManager::GUIManager(std::shared_ptr<Model> model,
                       int& argc,
                       char**& argv
                      ):argc_(argc),argv_(argv),model_(model) {
	stateObject_=std::make_unique<GTK_GUIStateObject>();

	auto& guido=GTK_GUIStateObject::getState(*stateObject_.get());

	auto app = Gtk::Application::create(argc_, argv_,"org.werner.erebus");

	guido.application_=app;

	auto builder=GTK_BuilderFactory::getBuilder(Windows::MAIN_WINDOW);

	GTK_MainWindow* window;
	builder->get_widget_derived("main_window", window);

	auto presenter=std::unique_ptr<IMainWindowPresenter>(new MainWindowPresenter);
	presenter->setWindow(window);

	window->setPresenter(std::move(presenter));

	guido.mainWindow_=std::unique_ptr<GTK_MainWindow>(window);
}

GUIManager::~GUIManager() {

}

GUIManager& GUIManager::create(std::shared_ptr<Model> model,int& argc, char**& argv) {
	if(guiManager_.get()==nullptr) {
		guiManager_=std::unique_ptr<GUIManager>(new GUIManager(model,argc,argv));
		return *guiManager_.get();
	}
	return *guiManager_.get();
}


GUIManager& GUIManager::getInstance() {
	return *guiManager_.get();
}

void GUIManager::runGUI() {
	auto& guido=GTK_GUIStateObject::getState(*stateObject_.get());


	guido.mainWindow_->setPreferredSize(800,600);
	guido.mainWindow_->maximize();

	guido.application_->run(*guido.mainWindow_.get());
}

void GUIManager::addWindow(IWindow& window) {
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
	BOOST_LOG_SEV(gtk_l::get(),normal)<<LOCATION<<"Moving view to new window";

	auto builder=GTK_BuilderFactory::getBuilder(Windows::VIEW_WINDOW);

	GTK_ViewWindow* viewWindow;
	builder->get_widget_derived("view_window", viewWindow);

	auto presenter=std::unique_ptr<IViewWindowPresenter>(
	                   std::make_unique<ViewWindowPresenter>());

	presenter->setWindow(viewWindow);

	viewWindow->setPresenter(std::move(presenter));

	viewWindow->getBasicViewContainer().addView(view);

	viewWindow->show();

	windows_.push_back(std::unique_ptr<IWindow>(viewWindow));
}

void GUIManager::showInfoDialog(std::string title,std::string text) {
	auto& guido=GTK_GUIStateObject::getState(*stateObject_.get());

	Gtk::MessageDialog dialog(*guido.mainWindow_, title);
	dialog.set_secondary_text(text);

	dialog.run();
}

}//namespace erebus

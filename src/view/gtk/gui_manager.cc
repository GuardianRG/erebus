#include <view/gui_manager.h>

#include <gtkmm.h>

#include <memory>

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
#include <presenter/main_window_presenter.h>
#include <presenter/view_window_presenter.h>


namespace erebus {

std::unique_ptr<GUIManager>	GUIManager::guiManager_=std::unique_ptr<GUIManager>(nullptr);

GUIManager::GUIManager(std::shared_ptr<Model> model,int& argc, char**& argv):argc_(argc),argv_(argv),model_(model) {
	stateObject_=std::unique_ptr<GTK_GUIStateObject>(new GTK_GUIStateObject);

	GTK_GUIStateObject* stateObject=GTK_GUIStateObject::getState(stateObject_.get());

	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc_, argv_,"org.werner.erebus");
	stateObject->application_=app;

	Glib::RefPtr<Gtk::Builder> builder;

	//load the main window
	builder=GTK_BuilderFactory::getBuilder("resources/main_window.glade");

	GTK_MainWindow* window;
	builder->get_widget_derived("main_window", window);

	auto presenter=std::unique_ptr<IMainWindowPresenter>(new MainWindowPresenter);
	presenter->setWindow(stateObject->mainWindow_.get());

	window->setPresenter(std::move(presenter));
	stateObject->mainWindow_=std::unique_ptr<GTK_MainWindow>(window);
	//end of loading main window

}

GUIManager::~GUIManager() {

}

GUIManager* GUIManager::create(std::shared_ptr<Model> model,int& argc, char**& argv) {
	if(guiManager_.get()==nullptr) {
		guiManager_=std::unique_ptr<GUIManager>(new GUIManager(model,argc,argv));
		return guiManager_.get();
	}
	return guiManager_.get();
}


GUIManager* GUIManager::getInstance() {
	return guiManager_.get();
}

void GUIManager::runGUI() {
	GTK_GUIStateObject* guido=GTK_GUIStateObject::getState(stateObject_.get());

	guido->mainWindow_->setPreferredSize(800,600);
	guido->mainWindow_->maximize();

	guido->application_->run(*(static_cast<GTK_MainWindow*>(guido->mainWindow_.get())));
}

void GUIManager::addWindow(IWindow* window) {
	GTK_GUIStateObject* stateObject=GTK_GUIStateObject::getState(stateObject_.get());
	GTK_Window* window_c=static_cast<GTK_Window*>(window);
	stateObject->application_->add_window(*window_c);
}

void GUIManager::moveViewToNewWindow(IView* view) {
	Glib::RefPtr<Gtk::Builder> builder;

	builder=GTK_BuilderFactory::getBuilder("resources/view_window.glade");

	GTK_ViewWindow* viewWindow;
	builder->get_widget_derived("view_window", viewWindow);

	auto presenter=std::unique_ptr<IViewWindowPresenter>(new ViewWindowPresenter);
	presenter->setWindow(viewWindow);

	viewWindow->setPresenter(std::move(presenter));

	viewWindow->addView(view);

	//addWindow(viewWindow);
	viewWindow->show();
}

}//namespace erebus

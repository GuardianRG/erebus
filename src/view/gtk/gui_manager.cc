#include <view/gui_manager.h>

#include <gtkmm.h>

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
GUIManager* GUIManager::guiManager_=nullptr;

GUIManager::GUIManager(Model* model,int& argc, char**& argv):argc_(argc),argv_(argv),model_(model) {
	stateObject_=new GTK_GUIStateObject;

	GTK_GUIStateObject* stateObject=GTK_GUIStateObject::getState(stateObject_);

	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc_, argv_,"org.werner.erebus");
	stateObject->application_=app;

	Glib::RefPtr<Gtk::Builder> builder;

	//load the main window
	builder=GTK_BuilderFactory::getBuilder("resources/main_window.glade");

	GTK_MainWindow* mw;
	builder->get_widget_derived("main_window", mw);

	mainWindow_=static_cast<IMainWindow*>(mw);

	IMainWindowPresenter* presenter=new MainWindowPresenter;
	presenter->setWindow(mainWindow_);

	mainWindow_->setPresenter(presenter);
	//end of loading main window

}

GUIManager::~GUIManager() {
	delete stateObject_;
}

GUIManager* GUIManager::create(Model* model,int& argc, char**& argv) {
	if(guiManager_==nullptr) {
		guiManager_=new GUIManager(model,argc,argv);
		return guiManager_;
	}
	return guiManager_;
}


GUIManager* GUIManager::getInstance() {
	return guiManager_;
}

void GUIManager::runGUI() {
	GTK_GUIStateObject* guido=GTK_GUIStateObject::getState(stateObject_);

	mainWindow_->setPreferredSize(800,600);
	mainWindow_->maximize();

	guido->application_->run(*(static_cast<GTK_MainWindow*>(mainWindow_)));
}

void GUIManager::addWindow(IWindow* window) {
	GTK_GUIStateObject* stateObject=GTK_GUIStateObject::getState(stateObject_);
	GTK_Window* window_c=static_cast<GTK_Window*>(window);
	stateObject->application_->add_window(*window_c);
}

void GUIManager::moveViewToNewWindow(IView* view) {
	Glib::RefPtr<Gtk::Builder> builder;

	builder=GTK_BuilderFactory::getBuilder("resources/view_window.glade");

	GTK_ViewWindow* viewWindow;
	builder->get_widget_derived("view_window", viewWindow);

	IViewWindowPresenter* presenter=new ViewWindowPresenter;
	presenter->setWindow(viewWindow);

	viewWindow->setPresenter(presenter);

	viewWindow->addView(view);

	//addWindow(viewWindow);
	viewWindow->show();
}

}//namespace erebus
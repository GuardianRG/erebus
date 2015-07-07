#include <view/gui_manager.h>

#include <gtkmm.h>

#include <iostream>

#include <gtk_builder_factory.h>
#include <gtk_main_window.h>
#include <view/interfaces/i_main_window.h>
#include <gtk_gui_state_object.h>

namespace erebus {
	
GUIManager::GUIManager(int& argc, char**& argv):argc_(argc),argv_(argv) {
	stateObject_=new GTK_GUIStateObject;
	
	GTK_GUIStateObject* guido=GTK_GUIStateObject::getState(stateObject_);
	
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc_, argv_,"org.werner.erebus");
	guido->application_=app;
	
	Glib::RefPtr<Gtk::Builder> builder;
	
	builder=GTK_BuilderFactory::getBuilder("resources/main_window.glade");
	
	GTK_MainWindow* mw;
	
	builder->get_widget_derived("main_window", mw);
	
	mainWindow_=static_cast<IMainWindow*>(mw);
	
}

GUIManager::~GUIManager() {
	delete stateObject_;
}

void GUIManager::runGUI() {
	GTK_GUIStateObject* guido=GTK_GUIStateObject::getState(stateObject_);
	
	mainWindow_->setPreferredSize(800,600);
	mainWindow_->maximize();
	
	guido->application_->run(*(static_cast<GTK_MainWindow*>(mainWindow_)));
}

}
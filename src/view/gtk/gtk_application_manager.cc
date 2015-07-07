#include <gtkmm.h>

#include <string>

#include <gtk_application_manager.h>
#include <gtk_widget_builder.h>
#include <main_view_presenter.h>

namespace erebus {
GtkApplicationManager::GtkApplicationManager(IModel* model,int& argc, char**& argv,std::string package) {
	app_= Gtk::Application::create(argc,argv,package);

	model_=model;

	initViews();
}

GtkApplicationManager::~GtkApplicationManager() {
	delete mainView_;
	delete mainViewPresenter_;
}

void GtkApplicationManager::initViews() {
	initMainView();
}

void GtkApplicationManager::initMainView() {
	mainViewPresenter_=new MainViewPresenter();
	mainViewPresenter_->setModel(model_);

	mainView_=GtkWidgetBuilder::buildMainView();
	mainView_->setPresenter(mainViewPresenter_);

	mainViewPresenter_->setView(mainView_);
}

void GtkApplicationManager::run() {
	app_->run(*mainView_);
}

}
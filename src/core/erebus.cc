#include <gtkmm.h>

#include <iostream>

#include <interfaces/i_application_manager.h>
#include <interfaces/i_model.h>

#include <gtk_main_view.h>
#include <main_view_presenter.h>
#include <model.h>
#include <gtk_application_manager.h>

int main(int argc, char *argv[]) {
	erebus::IModel *model=new erebus::Model();

	erebus::IApplicationManager *app=new erebus::GtkApplicationManager(model,argc,argv,"erebus");
	app->run();

	delete model;
	delete app;

	return 0;
}
#pragma once

#include <gtkmm.h>

#include <string>

#include <interfaces/i_application_manager.h>
#include <interfaces/i_model.h>
#include <interfaces/i_main_view_presenter.h>

#include <gtk_main_view.h>

namespace erebus {

/**
 * Manages a gtk application.
 */
class GtkApplicationManager : public IApplicationManager {
	Glib::RefPtr<Gtk::Application> 	app_;

	IModel*				model_;

	IMainViewPresenter*		mainViewPresenter_;

	GtkMainView*			mainView_;


	void initViews();
	void initMainView();

  public:
	/**
	 * Constructor.
	 *
	 * @param model the model to operate on
	 * @param argc argc from terminal
	 * @param argv argv from terminal
	 * @param package a unique name for the application
	 */
	GtkApplicationManager(IModel* model,int& argc, char**& argv,std::string package);

	/**
	 * copy constructor.
	 */
	GtkApplicationManager(const IApplicationManager &obj)=delete;

	/**
	 * Destructor.
	 */
	~GtkApplicationManager();


	/**
	 * See IApplicationManager::run()
	 */
	void run() override;

};

}
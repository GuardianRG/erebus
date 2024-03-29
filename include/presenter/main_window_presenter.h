#pragma once

#include <presenter/interfaces/i_main_window_presenter.h>

namespace erebus {

class IWindow;
class IMainWindow;

}

namespace erebus {

/**
 * This class is a concrete main window presenter.
 */
class MainWindowPresenter:public IMainWindowPresenter {
	IMainWindow*	mainWindow_;

  public:
	/**
	 * Constructor.
	 */
	MainWindowPresenter();

	/**
	 * Copy constructor.
	 *
	 * Deleted until needed.
	 */
	MainWindowPresenter(const MainWindowPresenter &obj)=delete;

	/**
	 * Move Constructor.
	 */
	MainWindowPresenter( MainWindowPresenter&& );

	/**
	 * Copy assignment operator.
	 *
	 * Cant be copied.
	 */
	MainWindowPresenter& operator=(const MainWindowPresenter&)=delete;

	/**
	 * Move assignment operator.
	 */
	MainWindowPresenter& operator=(MainWindowPresenter&&);

	/**
	 * Destructor.
	 */
	virtual ~MainWindowPresenter();


	/**
	 * See IMainWindowPresenter::setWindow.
	 */
	virtual void setWindow(IWindow& window) override;

	/**
	 * See IMainWindowPresenter::on_menu_view_new_window_click.
	 */
	virtual void on_menu_view_new_window_click()override;

	/**
	 * See IMainWindowPresenter::on_menu_view_save_preferences_click.
	 */
	virtual void on_menu_view_save_preferences_click()override;

	/**
	 * see IMainWindowPresenter::on_menu_view_restore_defaults_click.
	 */
	virtual void on_menu_view_restore_defaults_click()override;

};

}//namespace erbus

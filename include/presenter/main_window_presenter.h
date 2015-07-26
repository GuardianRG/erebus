#pragma once

#include <presenter/interfaces/i_main_window_presenter.h>
#include <view/interfaces/i_window.h>
#include <view/interfaces/i_main_window.h>

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
	 * See IMainWindowPresenter::setWindow
	 */
	virtual void setWindow(IWindow* window) override;
	
	/**
	 * See IMainWindowPresenter::on_menu_view_save_click
	 */
	virtual void on_menu_view_save_click()override;
	
	/**
	 * See IMainWindowPresenter::on_menu_view_show_tabs_click
	 */
	virtual void on_menu_view_show_tabs_click()override;
};

}//namespace erbus

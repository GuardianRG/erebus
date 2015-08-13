#pragma once

#include <presenter/interfaces/i_window_presenter.h>

namespace erebus {

/**
 * This class is the interface for a main window presenter.
 */
class IMainWindowPresenter:public IWindowPresenter {
  public:
	/**
	 * Destructor.
	 */
	virtual ~IMainWindowPresenter() {}

	/**
	 * Handels a click on the menu entry (view->"New Window").
	 */
	virtual void on_menu_view_new_window_click()=0;
	
	/**
	 * Handels a click on the menu entry (view->"Save Preferences").
	 */
	virtual void on_menu_view_save_preferences_click()=0;
	
	/**
	 * Handels a click on the menu entry (view->"Restore Defaults").
	 */
	virtual void on_menu_view_restore_defaults_click()=0;

};

}//namespace erbus

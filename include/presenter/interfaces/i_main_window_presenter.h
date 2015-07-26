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
	 * Handels a click on the menu->view->save entry.
	 */
	virtual void on_menu_view_save_click()=0;

	/**
	 * Handels a click on the menu->view->save entry.
	 */
	virtual void on_menu_view_show_tabs_click()=0;
};
}//namespace erbus

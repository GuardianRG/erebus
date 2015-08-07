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
	
};

}//namespace erbus

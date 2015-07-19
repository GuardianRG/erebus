#pragma once

#include <presenter/interfaces/i_presenter.h>
#include <view/interfaces/i_view.h>


namespace erebus {

/**
 * This class is the interface for a view presenter.
 */
class IViewPresenter:public IPresenter {
  public:
	/**
	 * Destructor.
	 */
	virtual ~IViewPresenter() {}

	/**
	 * Handels a click on the right mouse button.
	 */
	virtual void on_right_button_click()=0;

	/**
	 * Handels a click on the left mouse button.
	 */
	virtual void on_left_button_click()=0;

	/**
	 * Handels the close in the context menu.
	 */
	virtual void on_context_menu_close_click()=0;

	/**
	 * Handels the pop out in the context menu.
	 */
	virtual void on_context_menu_pop_out_click()=0;
};

}//namespace erbus

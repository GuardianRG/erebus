#pragma once

namespace erebus {

class IView;

}

namespace erebus {

/**
 * This class is the interface for a view presenter.
 */
class IViewPresenter {
  public:
	/**
	 * Destructor.
	 */
	virtual ~IViewPresenter() {}

	/**
	 * Sets the view of the presenter.
	 *
	 * @param click view the view of the presenter.
	 */
	virtual void setView(IView* view)=0;

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

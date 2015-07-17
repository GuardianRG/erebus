#pragma once

#include <presenter/interfaces/i_view_presenter.h>
#include <view/interfaces/i_view.h>

namespace erebus {

/**
 * This class is a conrete view presenter.
 */
class ViewPresenter :public IViewPresenter {
	IView* view_;

  public:
	/**
	 * Constructor.
	 */
	ViewPresenter();

	/**
	 * Copy constructor.
	 *
	 * Deleted until needed.
	 */
	ViewPresenter(const ViewPresenter &obj)=delete;

	/**
	 * Destructor.
	 */
	virtual ~ViewPresenter();

	/**
	 * See IViewPresenter::on_right_button_click
	 */
	virtual void on_right_button_click() override;

	/**
	 * See IViewPresenter::on_left_button_click
	 */
	virtual void on_left_button_click() override;

	/**
	 * See IViewPresenter::on_context_menu_close_click
	 */
	virtual void on_context_menu_close_click() override;

	/**
	 * See IViewPresenter::on_context_menu_pop_out_click
	 */
	virtual void on_context_menu_pop_out_click() override;

};

}//namespace erbus
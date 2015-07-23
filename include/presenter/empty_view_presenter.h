#pragma once

#include <view/interfaces/i_view.h>
#include <presenter/interfaces/i_empty_view_presenter.h>
#include <view/interfaces/i_empty_view.h>

namespace erebus {

/**
 * This class is a concrete empty view presenter.
 */
class EmptyViewPresenter :public IEmptyViewPresenter {
	IEmptyView* view_;
  public:
	/**
	 * Constructor.
	 */
	EmptyViewPresenter();

	/**
	 * Copy constructor.
	 *
	 * Cant be copied.
	 */
	EmptyViewPresenter(const EmptyViewPresenter &obj)=delete;

	/**
	 * Move Constructor.
	 */
	EmptyViewPresenter( EmptyViewPresenter&& );

	/**
	 * Copy assignment operator.
	 *
	 * Cant be copied.
	 */
	EmptyViewPresenter& operator=(const EmptyViewPresenter&)=delete;

	/**
	 * Move assignment operator.
	 */
	EmptyViewPresenter& operator=(EmptyViewPresenter&&);

	/**
	 * Destructor.
	 */
	virtual ~EmptyViewPresenter();



	/**
	 * See IEmptyViewPresenter::setView
	 */
	virtual void setView(IView* view) override;

	/**
	 * See IEmptyViewPresenter::on_right_button_click
	 */
	virtual void on_right_button_click() override;

	/**
	 * See IEmptyViewPresenter::on_left_button_click
	 */
	virtual void on_left_button_click() override;

	/**
	 * See IEmptyViewPresenter::on_context_menu_close_click
	 */
	virtual void on_context_menu_close_click() override;

	/**
	 * See IEmptyViewPresenter::on_context_menu_pop_out_click
	 */
	virtual void on_context_menu_pop_out_click() override;

};
}//namespace erbus

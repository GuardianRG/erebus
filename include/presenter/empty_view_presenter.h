#pragma once

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
	 * Deleted until needed.
	 */
	EmptyViewPresenter(const EmptyViewPresenter &obj)=delete;

	/**
	 * Destructor.
	 */
	virtual ~EmptyViewPresenter();

	/**
	 * See IEmptyViewPresenter::setView
	 */
	virtual void setView(IEmptyView* view) override;

	/**
	 * See IEmptyViewPresenter::getView
	 */
	virtual IEmptyView* getView() override;

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

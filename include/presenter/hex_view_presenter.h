#pragma once

#include <presenter/interfaces/i_hex_view_presenter.h>

#include <view/interfaces/i_view.h>
#include <view/interfaces/i_hex_view.h>

namespace erebus {

class HexViewPresenter:public IHexViewPresenter {
	IHexView*	view_;
  public:
	/**
	 * Constructor.
	 */
	HexViewPresenter();

	/**
	 * Copy constructor.
	 */
	HexViewPresenter(const HexViewPresenter &obj)=delete;

	/**
	 * Move Constructor.
	 */
	HexViewPresenter( HexViewPresenter&& );

	/**
	 * Copy assignment operator.
	 *
	 * Cant be copied.
	 */
	HexViewPresenter& operator=(const HexViewPresenter&)=delete;

	/**
	 * Move assignment operator.
	 */
	HexViewPresenter& operator=(HexViewPresenter&&);

	/**
	 * Destructor.
	 */
	virtual ~HexViewPresenter();



	/**
	 * See IHexViewPresenter::setView
	 */
	virtual void setView(IView& view)override;

	/**
	 * See IHexViewPresenter::on_right_button_click
	 */
	//virtual void on_right_button_click()override;

	/**
	 * See IHexViewPresenter::on_left_button_click
	 */
	//virtual void on_left_button_click()override;

	/**
	 * See IHexViewPresenter::on_context_menu_close_click
	 */
	//virtual void on_context_menu_close_click()override;

	/**
	 * See IHexViewPresenter::on_context_menu_pop_out_click
	 */
	//virtual void on_context_menu_pop_out_click()override;

};

}//namespace erebus

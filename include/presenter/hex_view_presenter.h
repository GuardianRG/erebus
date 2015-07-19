#include <presenter/interfaces/i_hex_view_presenter.h>

#include <view/interfaces/i_hex_view.h>

namespace erebus {

class HexViewPresenter:public IHexViewPresenter {
	IHexView*	view_;
  public:
	HexViewPresenter();

	HexViewPresenter(const HexViewPresenter &obj)=delete;

	virtual ~HexViewPresenter();

	/**
	 * See IHexViewPresenter::setView
	 */
	virtual void setView(IHexView* view)override;

	/**
	 * See IHexViewPresenter::getView
	 */
	virtual IHexView* getView()override;


	/**
	 * See IHexViewPresenter::on_right_button_click
	 */
	virtual void on_right_button_click()override;

	/**
	 * See IHexViewPresenter::on_left_button_click
	 */
	virtual void on_left_button_click()override;

	/**
	 * See IHexViewPresenter::on_context_menu_close_click
	 */
	virtual void on_context_menu_close_click()override;

	/**
	 * See IHexViewPresenter::on_context_menu_pop_out_click
	 */
	virtual void on_context_menu_pop_out_click()override;

};

}//namespace erebus

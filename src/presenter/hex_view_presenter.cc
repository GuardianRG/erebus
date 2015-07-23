#include <presenter/hex_view_presenter.h>

#include <view/interfaces/i_hex_view.h>

namespace erebus {

HexViewPresenter::HexViewPresenter() {

}

HexViewPresenter::~HexViewPresenter() {

}

void HexViewPresenter::setView(IHexView* view)  {
	view_=view;
}

IHexView* HexViewPresenter::getView() const {
	return view_;
}

void HexViewPresenter::on_right_button_click() {
	view_->showContextMenu();
}

void HexViewPresenter::on_left_button_click() {

}

void HexViewPresenter::on_context_menu_close_click() {
	view_->close();
}

void HexViewPresenter::on_context_menu_pop_out_click() {
	view_->popOut();
}

}//namespace erebus

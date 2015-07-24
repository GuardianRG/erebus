#include <presenter/hex_view_presenter.h>

#include <assert.h>

#include <view/interfaces/i_view.h>
#include <view/interfaces/i_hex_view.h>

namespace erebus {

HexViewPresenter::HexViewPresenter() {
	view_=nullptr;
}

HexViewPresenter::~HexViewPresenter() {

}

HexViewPresenter::HexViewPresenter( HexViewPresenter&& obj): view_(obj.view_) {

}

HexViewPresenter& HexViewPresenter::operator=(HexViewPresenter&& obj) {
	if(this != &obj) {
		view_=obj.view_;
	}
	return *this;
}


void HexViewPresenter::setView(IView* view)  {
	view_=dynamic_cast<IHexView*>(view);
	assert(view_!=0);
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

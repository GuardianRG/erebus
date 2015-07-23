#include <presenter/empty_view_presenter.h>

#include <view/interfaces/i_view.h>
#include <view/interfaces/i_empty_view.h>

namespace erebus {

EmptyViewPresenter::EmptyViewPresenter() {
	view_=nullptr;
}

EmptyViewPresenter::~EmptyViewPresenter() {

}

EmptyViewPresenter::EmptyViewPresenter( EmptyViewPresenter&& obj): view_(obj.view_) {

}

EmptyViewPresenter& EmptyViewPresenter::operator=(EmptyViewPresenter&& obj) {
	if(this != &obj) {
		view_=obj.view_;
	}
	return *this;
}

void EmptyViewPresenter::setView(IEmptyView* view) {
	view_=view;
}

IEmptyView* EmptyViewPresenter::getView() const {
	return view_;
}
void EmptyViewPresenter::on_right_button_click() {
	view_->showContextMenu();
}
void EmptyViewPresenter::on_left_button_click() {

}
void EmptyViewPresenter::on_context_menu_close_click() {
	view_->close();
}

void EmptyViewPresenter::on_context_menu_pop_out_click() {
	view_->popOut();
}

}//namespace erbus

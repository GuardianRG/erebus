#include <presenter/empty_view_presenter.h>

#include <view/interfaces/i_view.h>
#include <view/interfaces/i_empty_view.h>

namespace erebus {

EmptyViewPresenter::EmptyViewPresenter() {

}
EmptyViewPresenter::~EmptyViewPresenter() {
}

void EmptyViewPresenter::setView(IView* view) {
	view_=static_cast<IEmptyView*>(view);
}

IView* EmptyViewPresenter::getView() {
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
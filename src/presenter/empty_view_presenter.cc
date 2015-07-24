#include <presenter/empty_view_presenter.h>

#include <assert.h>

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

void EmptyViewPresenter::setView(IView* view) {
	view_=dynamic_cast<IEmptyView*>(view);
	assert(view_!=0);
}

void EmptyViewPresenter::on_right_button_click() {
	assert(view_!=nullptr);
	view_->showContextMenu();
}
void EmptyViewPresenter::on_left_button_click() {

}
void EmptyViewPresenter::on_context_menu_close_click() {
	assert(view_!=nullptr);
	view_->close();
}

void EmptyViewPresenter::on_context_menu_pop_out_click() {
	assert(view_!=nullptr);
	view_->popOut();
}

}//namespace erbus

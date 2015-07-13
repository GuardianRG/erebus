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
void EmptyViewPresenter::on_right_button_click() {
	view_->showContextMenu();
}
void EmptyViewPresenter::on_left_button_click() {
	
}

}
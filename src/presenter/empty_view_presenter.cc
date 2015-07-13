#include <presenter/empty_view_presenter.h>

namespace erebus {
EmptyViewPresenter::EmptyViewPresenter() {

}
EmptyViewPresenter::~EmptyViewPresenter() {
}

void EmptyViewPresenter::setView(IView* view) {
	ViewPresenter::setView(view);
}
void EmptyViewPresenter::on_right_button_click() {
	ViewPresenter::on_right_button_click();
}
void EmptyViewPresenter::on_left_button_click() {
	
}

void EmptyViewPresenter::setParent(IViewPresenter* parent) {
	ViewPresenter::setParent(parent);
}

}
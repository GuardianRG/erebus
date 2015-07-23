#include <presenter/view_window_presenter.h>

#include <view/interfaces/i_view_window.h>

namespace erebus {

ViewWindowPresenter::ViewWindowPresenter() {
	viewWindow_=nullptr;
}

ViewWindowPresenter::~ViewWindowPresenter() {

}

void ViewWindowPresenter::setWindow(IWindow* window) {
	viewWindow_=static_cast<IViewWindow*>(window);
}

IWindow* ViewWindowPresenter::getWindow() const {
	return viewWindow_;
}

}//namespace erebus

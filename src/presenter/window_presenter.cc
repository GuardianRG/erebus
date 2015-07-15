#include <presenter/window_presenter.h>

#include <view/interfaces/i_window.h>

namespace erebus {
WindowPresenter::WindowPresenter() {

}

WindowPresenter::~WindowPresenter() {

}

void WindowPresenter::setWindow(IWindow* window) {
	window_=static_cast<IWindow*>(window);
}

}//namespace erebus
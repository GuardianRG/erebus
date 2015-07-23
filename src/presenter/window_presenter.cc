#include <presenter/window_presenter.h>

#include <view/interfaces/i_window.h>

namespace erebus {
WindowPresenter::WindowPresenter() {
	window_=nullptr;
}

WindowPresenter::~WindowPresenter() {

}

WindowPresenter::WindowPresenter( WindowPresenter&& obj): window_(obj.window_) {

}

WindowPresenter& WindowPresenter::operator=(WindowPresenter&& obj) {
	if(this != &obj) {
		window_=obj.window_;
	}
	return *this;
}


void WindowPresenter::setWindow(IWindow* window) {
	window_=window;
}
}//namespace erebus

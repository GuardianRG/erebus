#include <presenter/view_window_presenter.h>

#include <assert.h>

#include <view/interfaces/i_view_window.h>

namespace erebus {

ViewWindowPresenter::ViewWindowPresenter() {
	viewWindow_=nullptr;
}

ViewWindowPresenter::~ViewWindowPresenter() {

}

ViewWindowPresenter::ViewWindowPresenter( ViewWindowPresenter&& obj): viewWindow_(obj.viewWindow_) {

}

ViewWindowPresenter& ViewWindowPresenter::operator=(ViewWindowPresenter&& obj) {
	if(this != &obj) {
		viewWindow_=obj.viewWindow_;
	}
	return *this;
}

void ViewWindowPresenter::setWindow(IWindow* window) {
	viewWindow_=dynamic_cast<IViewWindow*>(window);
	assert(viewWindow_!=0);
}


}//namespace erebus

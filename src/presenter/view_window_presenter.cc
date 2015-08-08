#include <view_window_presenter.h>

#include <stdexcept>

#include <i_view_window.h>
#include <presenter_logger.h>
#include <i_window.h>

INIT_LOCATION;

namespace erebus {

ViewWindowPresenter::ViewWindowPresenter() {
	viewWindow_=nullptr;
}

ViewWindowPresenter::~ViewWindowPresenter() {

}

ViewWindowPresenter::ViewWindowPresenter( ViewWindowPresenter&& obj):
	viewWindow_(obj.viewWindow_) {

}

ViewWindowPresenter& ViewWindowPresenter::operator=(ViewWindowPresenter&& obj) {
	if(this != &obj) {
		viewWindow_=obj.viewWindow_;
	}
	return *this;
}

void ViewWindowPresenter::setWindow(IWindow& window) {
	try {
		viewWindow_=&(dynamic_cast<IViewWindow&>(window));
	} catch(const std::bad_cast& e) {
		LOG_PRESENTER(error)<<"Cast failed.";
		throw;
	}
}


}//namespace erebus

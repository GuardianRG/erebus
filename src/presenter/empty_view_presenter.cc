#include <empty_view_presenter.h>

#include <stdexcept>

#include <i_view.h>
#include <i_empty_view.h>
#include <presenter_logger.h>

INIT_LOCATION;

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

void EmptyViewPresenter::setView(IView& view) {
	try {
		view_=&(dynamic_cast<IEmptyView&>(view));
	} catch(const std::bad_cast& e) {
		LOG_PRESENTER(error)<<"Cast failed.";
		throw;
	}
}

}//namespace erbus

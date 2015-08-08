#include <hex_view_presenter.h>

#include <assert.h>

#include <i_view.h>
#include <i_hex_view.h>
#include <presenter_logger.h>

INIT_LOCATION;

namespace erebus {

HexViewPresenter::HexViewPresenter() {
	view_=nullptr;
}

HexViewPresenter::~HexViewPresenter() {

}

HexViewPresenter::HexViewPresenter( HexViewPresenter&& obj): view_(obj.view_) {

}

HexViewPresenter& HexViewPresenter::operator=(HexViewPresenter&& obj) {
	if(this != &obj) {
		view_=obj.view_;
	}
	return *this;
}


void HexViewPresenter::setView(IView& view)  {
	try {
		view_=&(dynamic_cast<IHexView&>(view));
	} catch(const std::bad_cast& e) {
		LOG_PRESENTER(error)<<"Cast failed.";
		throw;
	}
}
}//namespace erebus

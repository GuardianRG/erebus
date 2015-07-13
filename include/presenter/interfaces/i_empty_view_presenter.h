#pragma once

#include <presenter/interfaces/i_view_presenter.h>

namespace erebus {

class IEmptyViewPresenter:public IViewPresenter {
  public:
	virtual ~IEmptyViewPresenter() {}
};

}
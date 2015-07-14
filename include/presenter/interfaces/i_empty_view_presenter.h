#pragma once

#include <presenter/interfaces/i_view_presenter.h>

namespace erebus {

/**
 * This class is the interfaces for a empty view presenter.
 */
class IEmptyViewPresenter:public IViewPresenter {
  public:
	/**
	 * Destructor.
	 */
	virtual ~IEmptyViewPresenter() {}
};

}//namespace erbus
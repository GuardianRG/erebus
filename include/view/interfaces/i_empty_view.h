#pragma once

#include <string>

#include <view/interfaces/i_view.h>
#include <presenter/interfaces/i_empty_view_presenter.h>
#include <view/interfaces/i_view_container.h>

namespace erebus {

/**
 * This class is the interface for a empty view.
 */
class IEmptyView:virtual public IView {
  public:
	/**
	 * Destructor.
	 */
	virtual ~IEmptyView() {}

};

}//namespace erbus
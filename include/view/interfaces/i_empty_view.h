#pragma once

#include <view/interfaces/i_view.h>

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

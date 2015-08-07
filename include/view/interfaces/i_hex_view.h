#pragma once


#include <string>

#include <view/interfaces/i_view.h>

namespace erebus {

}

namespace erebus {

/**
 * This class is the interface for a hex view.
 */
class IHexView:virtual public IView {

  public:
	/**
	 * Destructor.
	 */
	virtual ~IHexView() {}

};

}//namespace erebus

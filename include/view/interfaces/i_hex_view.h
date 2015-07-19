#pragma once


#include <string>

#include <view/interfaces/i_view.h>
#include <presenter/interfaces/i_hex_view_presenter.h>
#include <view/interfaces/i_view_container.h>

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

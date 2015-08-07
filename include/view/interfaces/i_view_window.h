#pragma once

#include <view/interfaces/i_window.h>

namespace erebus {
class IView;
}

namespace erebus {

/**
 * This class is the interface for a view window.
 */
class IViewWindow:virtual public IWindow {
  public:
	/**
	 * Destructor.
	 */
	virtual ~IViewWindow() {}

	virtual void addView(IView& view)=0;
};
}//namespace erebus

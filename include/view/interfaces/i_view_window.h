#pragma once

#include <view/interfaces/i_window.h>
#include <view/interfaces/i_view.h>

namespace erebus {

/**
 * This class is the interface for a view window.
 */
class IViewWindow:public IWindow {
  public:
	/**
	 * Destructor.
	 */
	virtual ~IViewWindow() {}

	/**
	 * Add the view to the window.
	 *
	 * The view gets added to the deepest view container.
	 *
	 * @param view view to add
	 */
	virtual void addView(IView* view)=0;
};
}//namespace erebus
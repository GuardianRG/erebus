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

	/**
	 * Adds the given view to the window.
	 *
	 * If the basic view container of the window is already splitted, nothing happens.
	 *
	 * @param view the view to add to the window
	 */
	virtual void addView(IView& view)=0;
	
	/**
	 * Whether the view window contains views.
	 * 
	 * @return true if the window contains views.
	 */
	virtual bool isEmpty()=0;
};

}//namespace erebus

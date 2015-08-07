#pragma once

#include <view/interfaces/i_window.h>
#include <presenter/interfaces/i_view_window_presenter.h>
#include <view/interfaces/i_view.h>

namespace erebus {
	class IViewContainer;
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
	 * Returns the basic view container.
	 *
	 * @return the basic view container
	 */
	virtual IViewContainer& getBasicViewContainer()=0;

	/**
	 * Whether the window contains any views.
	 *
	 * @return true if the window contains at least one view
	 */
	virtual bool isEmpty()const=0;
};
}//namespace erebus

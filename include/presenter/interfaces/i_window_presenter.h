#pragma once

namespace erebus {

class IWindow;

}

namespace erebus {

/**
 * This class is the base interface for a window presenter.
 */
class IWindowPresenter {
	
  public:
	/**
	 * Destructor.
	 */
	virtual ~IWindowPresenter() {}

	/**
	 * Sets the window to operate on.
	 *
	 * @param window the window to operate on
	 */
	virtual void setWindow(IWindow& window) =0;
};

}//namespace erbus

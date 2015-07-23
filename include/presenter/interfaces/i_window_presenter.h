#pragma once

#include <presenter/interfaces/i_presenter.h>
#include <view/interfaces/i_window.h>

namespace erebus {

/**
 * This class is the interface for a window presenter.
 */
class IWindowPresenter:public IPresenter {
  public:
	/**
	 * Destructor.
	 */
	virtual ~IWindowPresenter() {}

	/**
	 * Sets the window to operate on.
	 *
	 * @param window to operate on
	 */
	virtual void setWindow(IWindow* window) =0;

	/**
	 * Returns the window this presenter operates on.
	 *
	 * @return the window this presenter operates on
	 */
	virtual IWindow* getWindow() const=0;
};
}//namespace erbus

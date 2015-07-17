#pragma once

#include <presenter/interfaces/i_window_presenter.h>
#include <view/interfaces/i_window.h>

namespace erebus {

/**
 * This class is a concrete window presenter.
 */
class WindowPresenter:public IWindowPresenter {
	IWindow*	window_;
  public:
	/**
	 * Constructor.
	 */
	WindowPresenter();

	/**
	 * Copy constructor.
	 *
	 * Deleted until needed.
	 */
	WindowPresenter(const WindowPresenter &obj)=delete;

	/**
	 * Destructor.
	 */
	virtual ~WindowPresenter();

	/**
	 * See IWindowPresenter::setWindow
	 */
	virtual void setWindow(IWindow* window) override;

	/**
	 * See IWindowPresenter::getWindow
	 */
	virtual IWindow* getWindow() override;
};
}//namespace erebus
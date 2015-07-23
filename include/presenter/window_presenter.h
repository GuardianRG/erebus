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
	 * Move Constructor.
	 *
	 * Cant be copied. Must be constructed.
	 */
	WindowPresenter( WindowPresenter&& );

	/**
	 * Copy assignment operator.
	 *
	 * Cant be copied.
	 */
	WindowPresenter& operator=(const WindowPresenter&)=delete;

	/**
	 * Move assignment operator.
	 */
	WindowPresenter& operator=(WindowPresenter&&);

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
	virtual IWindow* getWindow() const override;
};
}//namespace erebus

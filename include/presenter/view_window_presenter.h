#pragma once

#include <presenter/interfaces/i_view_window_presenter.h>
#include <view/interfaces/i_view_window.h>

namespace erebus {
/**
 * This class is a concrete view window presenter.
 */
class ViewWindowPresenter:public IViewWindowPresenter {
	IViewWindow*	viewWindow_;

  public:
	/**
	 * Constructor.
	 */
	ViewWindowPresenter();

	/**
	 * Copy constructor.
	 *
	 * Deleted until needed.
	 */
	ViewWindowPresenter(const ViewWindowPresenter &obj)=delete;

	/**
	 * Move Constructor.
	 *
	 * Cant be copied. Must be constructed.
	 */
	ViewWindowPresenter( ViewWindowPresenter&& );

	/**
	 * Copy assignment operator.
	 *
	 * Cant be copied.
	 */
	ViewWindowPresenter& operator=(const ViewWindowPresenter&)=delete;

	/**
	 * Move assignment operator.
	 */
	ViewWindowPresenter& operator=(ViewWindowPresenter&&);

	/**
	 * Destructor.
	 */
	virtual ~ViewWindowPresenter();

	/**
	 * See IViewWindowPresenter::setWindow
	 */
	virtual void setWindow(IWindow* window) override;

	/**
	 * See IViewWindowPresenter::getWindow
	 */
	virtual IWindow* getWindow() const override;

};

}//namespace erebus

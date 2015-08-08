#pragma once

#include <presenter/interfaces/i_view_window_presenter.h>

namespace erebus {
class IViewWindow;
class IWindow;
}

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
	 * Cant be copied.
	 */
	ViewWindowPresenter(const ViewWindowPresenter &obj)=delete;

	/**
	 * Move Constructor.
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
	virtual void setWindow(IWindow& window) override;

};

}//namespace erebus

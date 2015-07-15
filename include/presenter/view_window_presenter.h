#pragma once

#include <presenter/interfaces/i_view_window_presenter.h>
#include <view/interfaces/i_view_window.h>

namespace erebus {
/**
 * This class is a concrete view window presenter.
 */
class ViewWindowPresenter:public IViewWindowPresenter {

	IViewWindow*	mainWindow_;
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
	 * Destructor.
	 */
	virtual ~ViewWindowPresenter();

	/**
	 * See IMainWindowPresenter::setWindow
	 */
	virtual void setWindow(IWindow* window) override;

};
}//namespace erebus
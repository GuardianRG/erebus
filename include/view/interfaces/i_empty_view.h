#pragma once

#include <string>

#include <presenter/interfaces/i_empty_view_presenter.h>
#include <view/interfaces/i_view_container.h>

namespace erebus {

/**
 * This class is the interface for a empty view.
 */
class IEmptyView {
  public:
	/**
	 * Destructor.
	 */
	virtual ~IEmptyView() {}




	/**
	 * See IView::setPresenter
	 */
	virtual void setPresenter(IEmptyViewPresenter* presenter)=0;

	/**
	 * See IView::getTitle
	 */
	virtual std::string getTitle()=0;

	/**
	 * See IView::setTitle
	 */
	virtual void setTitle(std::string title)=0;

	/**
	 * See IView::showContextMenu
	 */
	virtual void showContextMenu()=0;

	/**
	 * See IView::close
	 */
	virtual void close()=0;

	/**
	 * See IView::setParent
	 */
	virtual void setParent(IViewContainer* container)=0;

	/**
	 * See IView::getParent
	 */
	virtual IViewContainer* getParent()=0;

	/**
	 * See IView::popOut
	 */
	virtual void popOut()=0;
};

}//namespace erbus
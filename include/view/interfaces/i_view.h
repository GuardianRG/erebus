#pragma once

#include <string>

#include <view/interfaces/i_view.h>
#include <view/interfaces/i_view_container.h>

namespace erebus {

class IPresenter;

/**
 * This class is the interface for every view.
 */
class IView {
  public:
	/**
	 * Destructor.
	 */
	virtual ~IView() {}

	/**
	 * Sets the presenter for the view.
	 *
	 * @param presenter presenter for the view
	 */
	virtual void setPresenter(IPresenter* presenter)=0;

	/**
	 * Returns the title of the view.
	 *
	 * The title is the string that gets show e.g. in the tab's head
	 *
	 * @return title of the view
	 */
	virtual std::string getTitle()=0;

	/**
	 * Sets the title of the view.
	 *
	 * @param title new title of the view
	 */
	virtual void setTitle(std::string title)=0;

	/**
	 * Shows the context menu.
	 */
	virtual void showContextMenu()=0;

	/**
	 * Closes the view.
	 */
	virtual void close()=0;

	/**
	 * Sets the container in which the view is contained.
	 *
	 * @param container container of the view
	 */
	virtual void setViewContainer(IViewContainer* container)=0;

	/**
	 * Returns the container in which the view is contained.
	 *
	 * @return container in which the view is contained.
	 */
	virtual IViewContainer* getViewContainer()=0;
};

}//namespace erbus
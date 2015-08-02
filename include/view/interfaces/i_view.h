#pragma once

#include <string>
#include <memory>

#include <view/interfaces/i_view.h>
#include <view/interfaces/i_view_container.h>
#include <view/interfaces/i_gui_manager.h>

namespace erebus {

class IViewPresenter;

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
	 * Returns the title of the view.
	 *
	 * The title is the string that gets show e.g. in the tab's head
	 *
	 * @return title of the view
	 */
	virtual std::string getTitle() const=0;

	/**
	 * Sets the title of the view.
	 *
	 * @param title new title of the view
	 */
	virtual void setTitle(std::string title)=0;

	/**
	 * Shows the context menu.
	 *
	 * The context menu contains the special entries for the view
	 * as well as the standard entries.
	 */
	virtual void showContextMenu()=0;
	
	virtual void setGUIManager(IGUIManager* manager)=0;

	/**
	 * Closes the view.
	 */
	virtual void close()=0;

	/**
	 * Sets the container in which the view is contained.
	 *
	 * @param container container of the view
	 */
	virtual void setParent(IViewContainer* container)=0;

	/**
	 * Returns the container in which the view is contained.
	 *
	 * @return container in which the view is contained.
	 */
	virtual IViewContainer* getParent() const=0;

	/**
	 * Moves the view to a new window.
	 */
	virtual void popOut()=0;
};

}//namespace erbus

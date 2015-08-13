#pragma once

#include <string>

#include <view/interfaces/i_container.h>

namespace erebus {

enum class ViewType;
class IGUIManager;
class IView;

}

namespace erebus {

/**
 * This class is the interface for a view container.
 */
class IViewContainer:public IContainer {

  public:
	/**
	 * Destructor.
	 */
	virtual ~IViewContainer() {}

	/**
	 * Splits the container horizontal.
	 *
	 * If the container is already splitted nothings happens.
	 */
	virtual void splitHorizontal()=0;

	/**
	 * Splits the container vertically.
	 *
	 * If the container is already splitted nothings happens.
	 */
	virtual void splitVertical()=0;

	/**
	 * Wether the container is splitted or not.
	 *
	 * @return true, when the container is split
	 */
	virtual bool isSplitted() const=0;

	/**
	 * Wether this container contains container.
	 *
	 * @return is true when this container contains no containers
	 */
	virtual bool isTopLevel() const=0;

	/**
	 * Returns the view that is currently visible to the user.
	 *
	 * If no view was yet created, nullptr is returned.
	 *
	 * @return the view that is currently visible to the user
	 */
	virtual IView* getActiveView()=0;

	/**
	 * Removes the view from this container.
	 *
	 * Removes the view but does not delete it. This resposibility lies with the caller.
	 *
	 * @param view the view to be removed from the container
	 */
	virtual void removeView(IView& view)=0;

	/**
	 * Joins the container if it was splitted.
	 *
	 * If the container is not splitted nothing happens.
	 */
	virtual void join()=0;

	/**
	 * Shows the context menu.
	 *
	 * This method asks the currently visible view (if one exists) for the entries for
	 * the context menu and shows the too.
	 */
	virtual void showContextMenu()=0;

	/**
	 * Closes the given view.
	 *
	 * Caution: This method also deletes the view.
	 *
	 * @param view the view to close
	 */
	virtual void closeView(IView& view)=0;

	/**
	 * Closes the view that is currently visible to the user.
	 *
	 * See IViewContainer::closeView
	 */
	virtual void closeActiveView()=0;

	/**
	 * Adds a view to the container and shows it.
	 *
	 * @param type type of the view to add
	 */
	virtual void addView(ViewType type)=0;

	/**
	 * Adds the view to the container and shows it.
	 *
	 * It has to be ensured that the view is ready to be added to the container.
	 * (no other parent etc.)
	 *
	 * @param view the view to add to the container
	 */
	virtual void addView(IView& view)=0;

	/**
	 * Whether this container or its children contain views.
	 *
	 * @return true if views are contained
	 */
	virtual bool isEmpty()=0;


};

}//namespace erbus

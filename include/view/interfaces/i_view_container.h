#pragma once

#include <view/view_type.h>

namespace erebus {
//Forward declarations to avoid cyclic includation.
class IView;
class IViewContainerPresenter;

/**
 * This class is the interface for a view container.
 */
class IViewContainer {
  public:
	/**
	 * Destructor.
	 */
	virtual ~IViewContainer() {}

	/**
	 * Sets the container that this container contains.
	 *
	 * @parent parent of this container
	 */
	virtual void setParent(IViewContainer* parent)=0;

	/**
	 * Returns the container that this container contains.
	 *
	 * @return the parent of this container
	 */
	virtual IViewContainer* getParent() const=0;

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
	 * Sets if the tabs of the view should be show.
	 *
	 * @param showTabs true, if the tabs should be shown
	 */
	virtual void showTabs(bool showTabs)=0;

	/**
	 * Wether this container is empty.
	 *
	 * @param recursive when true, this call will be forwarded if the container is split
	 *
	 * @return true if the container is empty
	 */
	virtual bool isEmpty(bool recursive) const=0;

	/**
	 * Wether the container is split or not.
	 *
	 * @return true, when the container is split
	 */
	virtual bool isSplit() const=0;

	/**
	 * Wether this container contains container.
	 *
	 * @return is true when this container contains no containers
	 */
	virtual bool isTopLevel() const=0;

	/**
	 * Joins the container if it was split.
	 *
	 * If the container is not split nothing happens.
	 */
	virtual void joinContainer()=0;

	/**
	 * Shows the standard context menu.
	 */
	virtual void showContextMenu()=0;

	/**
	 * Adds a view.
	 *
	 * @param view view to add
	 */
	virtual void addView(IView* view)=0;

	/**
	 * Removs a view.
	 *
	 * @param view the view to remove
	 */
	virtual void removeView(IView* view)=0;

	/**
	 * Adds a view.
	 *
	 * @param type type of the view to add
	 */
	virtual void addView(ViewType type)=0;

	/**
	 * Pops the view out to a new window.
	 *
	 * @param view the view to pop out
	 */
	virtual void popOutView(IView* view)=0;

	/**
	 * Closes a view.
	 *
	 * @param view the view to close
	 */
	virtual void closeView(IView* view)=0;

};
}//namespace erbus

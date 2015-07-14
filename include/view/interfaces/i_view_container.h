#pragma once

#include <view/view_type.h>

namespace erebus {
//Forward declarations to avoid cyclic includation.
class IView;
class IViewContainerPresenter;

/**
 * This class is the interface for view container.
 */
class IViewContainer {
  public:
	/**
	 * Destructor.
	 */
	virtual ~IViewContainer() {}

	/**
	 * Sets the presenter for this container.
	 *
	 * @param presenter presenter for this container
	 */
	virtual void setPresenter(IViewContainerPresenter* presenter)=0;

	/**
	 * Sets the container that this container contains.
	 *
	 * @parent parent of this container
	 */
	virtual void setParent(IViewContainer* parent)=0;

	/**
	 * Splits the container horizontal.
	 *
	 * Is the container is already splitted nothings happens.
	 */
	virtual void splitHorizontal()=0;

	/**
	 * Splits the container vertically.
	 *
	 * Is the container is already splitted nothings happens.
	 */
	virtual void splitVertical()=0;

	/**
	 * Sets if the tabs of the view should be show.
	 *
	 * @param showTabs true, if the tabs should be shown
	 */
	virtual void showTabs(bool showTabs)=0;

	/**
	 * @return is true when this container contains no views.
	 */
	virtual bool isEmpty()=0;

	/**
	 * Wether the container is splittet or not.
	 *
	 * @return true, when the container is splitte
	 */
	virtual bool isSplittet()=0;

	/**
	 * @return is true when this container has not yet been split.
	 */
	virtual bool isTopLevel()=0;

	/**
	 * Joins the container if it was split.
	 *
	 * If the container is not split nothing happens.
	 */
	virtual void joinContainer()=0;

	/**
	 * Shows the context menu.
	 */
	virtual void showContextMenu()=0;

	/**
	 * Adds a view.
	 *
	 * @param view view to add
	 */
	virtual void addView(IView* view)=0;

	/**
	 * Adds a view.
	 *
	 * @param type type of the view to add
	 */
	virtual void addView(ViewType type)=0;

	/**
	 * Closes a view.
	 *
	 * @param view the view to close
	 */
	virtual void closeView(IView* view)=0;

};
}//namespace erbus
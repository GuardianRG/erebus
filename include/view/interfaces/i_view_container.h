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
	 * @return is true when this container has not yet been split.
	 */
	virtual bool isTopLevel()=0;

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
};
}//namespace erbus
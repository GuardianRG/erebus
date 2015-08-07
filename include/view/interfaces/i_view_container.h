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
	 * Sets if the tabs of the view should be show.
	 *
	 * @param showTabs true, if the tabs should be shown
	 */
	//virtual void showTabs(bool showTabs)=0;

	/**
	 * Wether this container is empty.
	 *
	 * @param recursive when true, this call will be forwarded if the container is split
	 *
	 * @return true if the container is empty
	 */
	//virtual bool isEmpty(bool recursive) const=0;

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

	virtual IView* getActiveView()=0;

	virtual void removeView(IView& view)=0;

	/**
	 * Joins the container if it was split.
	 *
	 * If the container is not split nothing happens.
	 */
	virtual void join()=0;

	/**
	 * Shows the standard context menu.
	 */
	virtual void showContextMenu()=0;

	/**
	 * Adds a view.
	 *
	 * @param view view to add
	 */
	//virtual void addView(IView& view)=0;

	/**
	 * Removs a view.
	 *
	 * @param view the view to remove
	 */
	virtual void closeView(IView& view)=0;

	virtual void closeActiveView()=0;

	/**
	 * Adds a view.
	 *
	 * @param type type of the view to add
	 */
	virtual void addView(ViewType type)=0;


	virtual void addView(IView& view)=0;

	/**
	 * Pops the view out to a new window.
	 *
	 * @param view the view to pop out
	 */
	//virtual void popOutView(IView& view)=0;

	/**
	 * Closes a view.
	 *
	 * @param view the view to close
	 */
	//virtual void closeView(IView& view)=0;

};
}//namespace erbus

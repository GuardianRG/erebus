#pragma once

#include <view/view_type.h>
#include <view/interfaces/i_view_container.h>

namespace erebus {

/**
 * This class is the interface for a view container presenter.
 */
class IViewContainerPresenter {
  public:
	/**
	 * Destructor.
	 */
	virtual ~IViewContainerPresenter() {}

	/**
	 * Sets the view container.
	 *
	 * @param container the container
	 */
	virtual void setViewContainer(IViewContainer* container)=0;

	/**
	 * Handels a right mouse button click.
	 */
	virtual void on_right_button_click()=0;

	/**
	 * Handels a left mouse button click.
	 */
	virtual void on_left_button_click()=0;

	/**
	 * Handels the split view horizontal in the context menu.
	 */
	virtual void on_context_menu_split_view_horizontal_click()=0;

	/**
	 * Handels the split view vertical in the context menu.
	 */
	virtual void on_context_menu_split_view_vertical_click()=0;

	/**
	 * Handels a click on a wie to add in the context menu.
	 *
	 * @param type the type of the view to add
	 */
	virtual void on_context_menu_add_view_click(ViewType type)=0;
};
}//namespace erbus
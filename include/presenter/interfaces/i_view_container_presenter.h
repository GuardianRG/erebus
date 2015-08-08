#pragma once

#include <memory>

namespace erebus {

enum class ViewType;
class IViewContainer;

}

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
	 * @param container the container to set
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
	 * Handels a click on the context menu entry "Join".
	 */
	virtual void on_context_menu_join_click()=0;

	/**
	 * Handels a click on the context menu entry "Split horizontal".
	 */
	virtual void on_context_menu_split_horizontal_click()=0;

	/**
	 * Handels a click on the context menu entry "Close".
	 */
	virtual void on_context_menu_close_click()=0;

	/**
	 * Handels a click on the context menu entry "Pop out".
	 */
	virtual void on_context_menu_pop_out_click()=0;

	/**
	 * Handels a click on the context menu entry "Split vertically".
	 */
	virtual void on_context_menu_split_vertical_click()=0;

	/**
	 * Handels a click on any of the context menu entries in the submenu "Add view".
	 *
	 * @param type the type of the view to add
	 */
	virtual void on_context_menu_add_view_click(ViewType type)=0;

};
}//namespace erbus

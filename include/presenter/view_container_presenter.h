#pragma once

#include <presenter/interfaces/i_view_container_presenter.h>
#include <view/interfaces/i_view_container.h>



namespace erebus {

/**
 * This class is concrete view container presenter.
 */
class ViewContainerPresenter:public IViewContainerPresenter {
	IViewContainer*		container_;

  public:
	/**
	 * Constructor.
	 */
	ViewContainerPresenter();

	/**
	 * Copy constructor.
	 *
	 * deleted until needed.
	 */
	ViewContainerPresenter(const ViewContainerPresenter &obj)=delete;

	/**
	 * Destructor.
	 */
	virtual ~ViewContainerPresenter();


	/**
	 * See IViewContainerPresenter::setViewContainer
	 */
	virtual void setViewContainer(IViewContainer* container) override;

	/**
	 * See IViewContainerPresenter::on_right_button_click
	 */
	virtual void on_right_button_click()override;

	/**
	 * See IViewContainerPresenter::on_left_button_click
	 */
	virtual void on_left_button_click()override;

	/**
	 * See IViewContainerPresenter::on_context_menu_split_view_vertical_click
	 */
	virtual void on_context_menu_split_view_vertical_click()override;

	/**
	 * See IViewContainerPresenter::on_context_menu_split_view_horizontal_click
	 */
	virtual void on_context_menu_split_view_horizontal_click()override;

	/**
	 * See IViewContainerPresenter::on_context_menu_add_view_click
	 */
	virtual void on_context_menu_add_view_click(ViewType type)override;
};
}//namespace erbus
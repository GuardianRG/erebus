#pragma once

#include <presenter/interfaces/i_view_container_presenter.h>

namespace erebus {
class IViewContainer;
enum class ViewType;
}

namespace erebus {

/**
 * This class is concrete view container presenter.
 */
class ViewContainerPresenter:public IViewContainerPresenter {
	IViewContainer*			container_;
	//std::unique_ptr<IViewContainerSettingsPropagator>	propagator_;
  public:
	/**
	 * Constructor.
	 */
	ViewContainerPresenter();

	/**
	 * Copy constructor.
	 *
	 * Cant be copied.
	 */
	ViewContainerPresenter(const ViewContainerPresenter &obj)=delete;

	/**
	 * Move Constructor.
	 */
	ViewContainerPresenter( ViewContainerPresenter&& );

	/**
	 * Copy assignment operator.
	 *
	 * Cant be copied.
	 */
	ViewContainerPresenter& operator=(const ViewContainerPresenter&)=delete;

	/**
	 * Move assignment operator.
	 */
	ViewContainerPresenter& operator=(ViewContainerPresenter&&);

	/**
	 * Destructor.
	 */
	virtual ~ViewContainerPresenter();


	/**
	 * IViewContainerPresenter::setSettingsPropagator
	 */
	//virtual void setSettingsPropagator(
	//  std::unique_ptr<IViewContainerSettingsPropagator> p)override;

	/**
	 * See IViewContainerPresenter::setViewContainer
	 */
	virtual void setViewContainer(IViewContainer* container) override;

	/**
	 * See IViewContainerPresenter::on_context_menu_join_click
	 */
	virtual void on_context_menu_join_click()override;

	/**
	 * See IViewContainerPresenter::on_right_button_click
	 */
	virtual void on_right_button_click()override;

	/**
	 * See IViewContainerPresenter::on_left_button_click
	 */
	virtual void on_left_button_click()override;

	/**
	 * See IViewContainerPresenter::on_context_menu_close_click
	 */
	virtual void on_context_menu_close_click()override;
	virtual void on_context_menu_pop_out_click()override;

	/**
	 * See IViewContainerPresenter::on_context_menu_split_view_vertical_click
	 */
	virtual void on_context_menu_split_vertical_click()override;

	/**
	 * See IViewContainerPresenter::on_context_menu_split_view_horizontal_click
	 */
	virtual void on_context_menu_split_horizontal_click()override;

	/**
	 * See IViewContainerPresenter::on_context_menu_add_view_click
	 */
	virtual void on_context_menu_add_view_click(ViewType type)override;
};
}//namespace erbus

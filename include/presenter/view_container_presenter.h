#pragma once

#include <presenter/interfaces/i_view_container_presenter.h>



namespace erebus {
class ViewContainerPresenter:public IViewContainerPresenter {
	IViewContainer*	view_;
  public:
	ViewContainerPresenter();
	~ViewContainerPresenter();


	virtual void setView(IViewContainer* view)override;

	virtual void on_right_button_click()override;

	virtual void on_left_button_click()override;


	virtual void on_context_menu_split_view_vertical_click()override;


	virtual void on_context_menu_split_view_horizontal_click()override;
	virtual void on_context_menu_add_view_click(ViewType type)override;
};
}
#pragma once

#include <view/interfaces/i_view_container.h>

namespace erebus {

class IViewContainerPresenter {
  public:
	virtual ~IViewContainerPresenter() {}

	virtual void setView(IViewContainer* view)=0;
	virtual void on_right_button_click()=0;
	virtual void on_left_button_click()=0;
	virtual void on_context_menu_split_view_horizontal_click()=0;
	virtual void on_context_menu_split_view_vertical_click()=0;
};
}
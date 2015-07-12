#pragma once

#include <presenter/interfaces/i_presenter.h>
#include <view/interfaces/i_view.h>


namespace erebus {

class IViewPresenter:public IPresenter {
  public:
	virtual ~IViewPresenter() {}

	virtual void on_right_button_click()=0;
	virtual void on_left_button_click()=0;

	virtual void setView(IView* view)=0;

	virtual void setParent(IViewPresenter* parent)=0;

	virtual void splitView()=0;

	virtual void on_popup_menu_view_split_view_click()=0;
};

}
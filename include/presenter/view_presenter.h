#pragma once

#include <presenter/interfaces/i_view_presenter.h>
#include <view/interfaces/i_view.h>

namespace erebus {

class ViewPresenter :public IViewPresenter {
	IView* view_;

	IViewPresenter*	parent_;
  public:
	ViewPresenter();
	virtual ~ViewPresenter();

	void setView(IView* view) override;
	void on_right_button_click() override;
	void on_left_button_click() override;


};


}
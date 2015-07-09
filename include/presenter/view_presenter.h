#pragma once

#include <presenter/interfaces/i_view_presenter.h>
#include <view/interfaces/i_view.h>

namespace erebus {

	class ViewPresenter :public IViewPresenter{
		IView* view_;
	public:
		ViewPresenter();
		virtual ~ViewPresenter();
		
		virtual void setView(IView* view) override;
		virtual void on_right_button_click() override;
		virtual void on_left_button_click() override;
	};

	
}
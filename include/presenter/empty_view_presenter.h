#pragma once

#include <presenter/interfaces/i_empty_view_presenter.h>
#include <view/interfaces/i_empty_view.h>

namespace erebus {
class EmptyViewPresenter :public IEmptyViewPresenter {
	IEmptyView* view_;
  public:
	EmptyViewPresenter();

	EmptyViewPresenter(const EmptyViewPresenter &obj)=delete;

	~EmptyViewPresenter();

	void setView(IView* view) override;
	void on_right_button_click() override;
	void on_left_button_click() override;

};
}
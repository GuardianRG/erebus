#pragma once

#include <presenter/interfaces/i_empty_view_presenter.h>
#include <presenter/view_presenter.h>

namespace erebus {
class EmptyViewPresenter :public ViewPresenter,public IEmptyViewPresenter {
  public:
	EmptyViewPresenter();

	EmptyViewPresenter(const EmptyViewPresenter &obj)=delete;

	~EmptyViewPresenter();

	void setView(IView* view) override;
	void on_right_button_click() override;
	void on_left_button_click() override;
	void setParent(IViewPresenter* parent) override;

};
}
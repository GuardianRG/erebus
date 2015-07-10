#include <presenter/view_presenter.h>
#include <view/interfaces/i_view.h>

#include <iostream>

namespace erebus {
	ViewPresenter::ViewPresenter() {
		
	}
	ViewPresenter::~ViewPresenter() {
		
	}
	
	void ViewPresenter::setView(IView* view) {
		view_=view;
	}
	void ViewPresenter::on_right_button_click() {
		view_->showContextMenu();
	}
	void ViewPresenter::on_left_button_click() {
		
	}
	
	void ViewPresenter::setParent(IViewPresenter* parent) {
		parent_=parent;
	}
	
	void ViewPresenter::splitView() {
		view_->splitView();
	}
	
	void ViewPresenter::on_popup_menu_view_split_view_click() {
		parent_->splitView();
	}
}
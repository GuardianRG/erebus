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
		std::cout<<"RIGHT"<<std::endl;
	}
	void ViewPresenter::on_left_button_click() {
		std::cout<<"LEFT"<<std::endl;
		
	}
}
#include <presenter/view_container_presenter.h>

#include <iostream>

namespace erebus {
ViewContainerPresenter::ViewContainerPresenter() {

}

ViewContainerPresenter::~ViewContainerPresenter() {

}

void ViewContainerPresenter::on_right_button_click() {
	if(view_->isTopLevelContainer())
		view_->showContextMenu();
	//view_->showContextMenu();
}
void ViewContainerPresenter::on_left_button_click() {
	//if(view_->isTopLevelContainer())
	//std::cout << "LEFT"<<std::endl;
}

void ViewContainerPresenter::on_context_menu_split_view_horizontal_click() {
	view_->splitHorizontal();
}
void ViewContainerPresenter::on_context_menu_split_view_vertical_click() {
	view_->splitVertical();
}

void ViewContainerPresenter::setView(IViewContainer* view) {
	view_=view;
}
}
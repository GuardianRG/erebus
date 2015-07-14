#include <presenter/view_container_presenter.h>


namespace erebus {
ViewContainerPresenter::ViewContainerPresenter() {

}

ViewContainerPresenter::~ViewContainerPresenter() {

}

void ViewContainerPresenter::on_right_button_click() {
	if(container_->isTopLevel()&&container_->isEmpty())
		container_->showContextMenu();
}
void ViewContainerPresenter::on_left_button_click() {
	
}

void ViewContainerPresenter::on_context_menu_split_view_horizontal_click() {
	container_->splitHorizontal();
}
void ViewContainerPresenter::on_context_menu_split_view_vertical_click() {
	container_->splitVertical();
}

void ViewContainerPresenter::on_context_menu_add_view_click(ViewType type) {
	container_->addView(type);
}

void ViewContainerPresenter::setViewContainer(IViewContainer* container) {
	container_=container;
}
}//namespace erbus
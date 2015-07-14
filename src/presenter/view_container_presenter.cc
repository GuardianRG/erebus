#include <presenter/view_container_presenter.h>


namespace erebus {
ViewContainerPresenter::ViewContainerPresenter() {
	parent_=nullptr;
	container_=nullptr;
}

ViewContainerPresenter::~ViewContainerPresenter() {

}

void ViewContainerPresenter::on_right_button_click() {
	if(container_->isTopLevel()&&container_->isEmpty())
		container_->showContextMenu();
}
void ViewContainerPresenter::on_left_button_click() {

}

void ViewContainerPresenter::on_context_menu_split_horizontal_click() {
	container_->splitHorizontal();
}
void ViewContainerPresenter::on_context_menu_split_vertical_click() {
	container_->splitVertical();
}

void ViewContainerPresenter::on_context_menu_add_view_click(ViewType type) {
	container_->addView(type);
}

IViewContainer* ViewContainerPresenter::getViewContainer() {
	return container_;
}

void ViewContainerPresenter::setViewContainer(IViewContainer* container) {
	container_=container;
}

void ViewContainerPresenter::on_context_menu_join_click() {
	if(container_->isTopLevel()&&parent_!=nullptr)
		parent_->getViewContainer()->joinContainer();
	//if(container_->isTopLevel())
	//container_->joinContainer();
}
void ViewContainerPresenter::setParent(IViewContainerPresenter* parent) {
	parent_=parent;
}
}//namespace erbus
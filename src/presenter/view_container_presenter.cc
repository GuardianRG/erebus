#include <presenter/view_container_presenter.h>


namespace erebus {
ViewContainerPresenter::ViewContainerPresenter() {
	container_=nullptr;
}

ViewContainerPresenter::~ViewContainerPresenter() {

}

ViewContainerPresenter::ViewContainerPresenter( ViewContainerPresenter&& obj): container_(obj.container_) {

}

ViewContainerPresenter& ViewContainerPresenter::operator=(ViewContainerPresenter&& obj) {
	if(this != &obj) {
		container_=obj.container_;
	}
	return *this;
}

void ViewContainerPresenter::on_right_button_click() {
	if(container_->isEmpty())
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

IViewContainer* ViewContainerPresenter::getViewContainer() const {
	return container_;
}

void ViewContainerPresenter::setViewContainer(IViewContainer* container) {
	container_=container;
}

void ViewContainerPresenter::on_context_menu_join_click() {
	if(container_->getParent()!=nullptr)
		container_->getParent()->joinContainer();
}
}//namespace erbus

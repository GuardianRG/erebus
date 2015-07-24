#include <presenter/view_container_presenter.h>

#include <assert.h>

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
	assert(container_!=nullptr);
	if(container_->isEmpty(false))
		container_->showContextMenu();
}
void ViewContainerPresenter::on_left_button_click() {

}

void ViewContainerPresenter::on_context_menu_split_horizontal_click() {
	assert(container_!=nullptr);
	container_->splitHorizontal();
}
void ViewContainerPresenter::on_context_menu_split_vertical_click() {
	assert(container_!=nullptr);
	container_->splitVertical();
}

void ViewContainerPresenter::on_context_menu_add_view_click(ViewType type) {
	assert(container_!=nullptr);
	container_->addView(type);
}

void ViewContainerPresenter::setViewContainer(IViewContainer* container) {
	container_=container;
	assert(container_!=nullptr);
}

void ViewContainerPresenter::on_context_menu_join_click() {
	assert(container_!=nullptr);
	if(container_->getParent()!=nullptr)
		container_->getParent()->joinContainer();
}
}//namespace erbus

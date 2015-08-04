#include <presenter/view_container_presenter.h>

#include <memory>

#include <view/interfaces/i_view_container.h>

#include <presenter/presenter_logger.h>

INIT_LOCATION;

namespace erebus {

ViewContainerPresenter::ViewContainerPresenter() {
	container_=nullptr;
}

ViewContainerPresenter::~ViewContainerPresenter() {

}

ViewContainerPresenter::ViewContainerPresenter( ViewContainerPresenter&& obj):
	container_(obj.container_) {

}

ViewContainerPresenter& ViewContainerPresenter::operator=
(ViewContainerPresenter&& obj) {
	if(this != &obj) {
		container_=obj.container_;
	}
	return *this;
}

void ViewContainerPresenter::on_right_button_click() {
	LOG_ASSERT(presenter_l::get(),container_!=nullptr);

	//if(container_->isEmpty(false))
	container_->showContextMenu();
}
void ViewContainerPresenter::on_left_button_click() {

}
/*
void ViewContainerPresenter::setSettingsPropagator(
    std::unique_ptr<IViewContainerSettingsPropagator> p) {
	propagator_=std::move(p);
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
*/
void ViewContainerPresenter::setViewContainer(IViewContainer* container) {
	container_=container;
	LOG_ASSERT(presenter_l::get(),container_!=nullptr);
}
/*
void ViewContainerPresenter::on_context_menu_join_click() {
	assert(container_!=nullptr);

}*/

}//namespace erbus

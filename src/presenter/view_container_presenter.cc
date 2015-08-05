#include <presenter/view_container_presenter.h>

#include <memory>

#include <view/interfaces/i_view_container.h>
#include <view/interfaces/i_gui_manager.h>

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

	if(container_->isTopLevel())
		container_->showContextMenu();
}
void ViewContainerPresenter::on_left_button_click() {

}
/*
void ViewContainerPresenter::setSettingsPropagator(
    std::unique_ptr<IViewContainerSettingsPropagator> p) {
	propagator_=std::move(p);
}
*/
void ViewContainerPresenter::on_context_menu_split_horizontal_click() {
	LOG_ASSERT(presenter_l::get(),container_!=nullptr);

	container_->splitHorizontal();
}
void ViewContainerPresenter::on_context_menu_split_vertical_click() {
	LOG_ASSERT(presenter_l::get(),container_!=nullptr);

	container_->splitVertical();
}
/*
void ViewContainerPresenter::on_context_menu_add_view_click(ViewType type) {
	assert(container_!=nullptr);
	container_->addView(type);
}
*/
void ViewContainerPresenter::setViewContainer(IViewContainer* container) {
	LOG_ASSERT(presenter_l::get(),container!=nullptr);
	container_=container;
}

void ViewContainerPresenter::on_context_menu_join_click() {
	LOG_ASSERT(presenter_l::get(),container_!=nullptr);

	container_->getGUIManager().joinContainer(container_->getID());
}

}//namespace erbus

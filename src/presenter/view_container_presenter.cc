#include <view_container_presenter.h>

#include <i_view_container.h>
#include <i_gui_manager.h>

#include <presenter_logger.h>
#include <view_type.h>

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

void ViewContainerPresenter::on_context_menu_split_horizontal_click() {
	LOG_ASSERT(presenter_l::get(),container_!=nullptr);

	container_->splitHorizontal();
}
void ViewContainerPresenter::on_context_menu_split_vertical_click() {
	LOG_ASSERT(presenter_l::get(),container_!=nullptr);

	container_->splitVertical();
}

void ViewContainerPresenter::on_context_menu_close_click() {
	LOG_ASSERT(presenter_l::get(),container_!=nullptr);

	container_->closeActiveView();
}

void ViewContainerPresenter::on_context_menu_pop_out_click() {
	LOG_ASSERT_PRESENTER(container_!=nullptr);

	auto view=container_->getActiveView();
	if(view!=nullptr) {
		container_->removeView(*view);
		container_->getGUIManager().moveViewToNewWindow(*view);
	}
}

void ViewContainerPresenter::on_context_menu_add_view_click(ViewType type) {
	LOG_ASSERT(presenter_l::get(),container_!=nullptr);

	container_->addView(type);
}

void ViewContainerPresenter::setViewContainer(IViewContainer* container) {
	LOG_ASSERT(presenter_l::get(),container!=nullptr);

	container_=container;
}

void ViewContainerPresenter::on_context_menu_join_click() {
	LOG_ASSERT(presenter_l::get(),container_!=nullptr);

	container_->getGUIManager().joinContainer(container_->getID());
}

}//namespace erbus

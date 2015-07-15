#include <gtk_view_window.h>

#include <string>

#include <presenter/interfaces/i_presenter.h>
#include <presenter/interfaces/i_view_window_presenter.h>

#include <gtk_view_container.h>
#include <presenter/view_container_presenter.h>

#include <view/view_type.h>

#include <iostream>

namespace erebus  {

GTK_ViewWindow::GTK_ViewWindow() {
}

GTK_ViewWindow::GTK_ViewWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder):Gtk::Window(cobject) {
	Gtk::Viewport *base;
	refBuilder->get_widget("basic_viewport",base);

	ViewContainerPresenter* presenter=new ViewContainerPresenter;
	container_=new GTK_ViewContainer(base->get_hadjustment(),base->get_vadjustment(),nullptr,nullptr);

	presenter->setViewContainer(container_);
	container_->setPresenter(presenter);

	base->add(*container_);

	setPreferredSize(300,200);

	show_all_children();
}

GTK_ViewWindow::~GTK_ViewWindow() {

}

void GTK_ViewWindow::setTitle(std::string title) {
	set_title(title);
}

void GTK_ViewWindow::setPreferredSize(int width,int height) {
	set_default_size(width,height);
}

void GTK_ViewWindow::maximize() {
	Gtk::Window::maximize();
}


void GTK_ViewWindow::unmaximize() {
	Gtk::Window::unmaximize();
}

void GTK_ViewWindow::setPresenter(IPresenter* presenter) {
	presenter_=static_cast<IViewWindowPresenter*>(presenter);
}

void GTK_ViewWindow::addView(IView* view) {
	container_->addView(view);
	show_all_children();
}

}//namespace erebus
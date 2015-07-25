#include <gtk_view_window.h>

#include <string>
#include <memory>

#include <presenter/interfaces/i_view_window_presenter.h>

#include <gtk_view_container.h>
#include <presenter/view_container_presenter.h>

#include <view/view_type.h>


namespace erebus  {
GTK_ViewWindow::GTK_ViewWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder):GTK_Window(cobject) {
	Gtk::Viewport *base;
	refBuilder->get_widget("basic_viewport",base);

	auto presenter=std::unique_ptr<ViewContainerPresenter>(new ViewContainerPresenter);
	container_=Gtk::manage(new GTK_ViewContainer(base->get_hadjustment(),base->get_vadjustment(),nullptr));

	presenter->setViewContainer(container_);
	container_->setPresenter(std::move(presenter));

	base->add(*container_);

	setPreferredSize(300,200);

	show_all_children();
}

GTK_ViewWindow::~GTK_ViewWindow() {

}

void GTK_ViewWindow::setTitle(std::string title) {
	GTK_Window::setTitle(title);
}

std::string GTK_ViewWindow::getTitle() const {
	return GTK_Window::getTitle();
}

void GTK_ViewWindow::setPreferredSize(int width,int height) {
	GTK_Window::setPreferredSize(width,height);
}

void GTK_ViewWindow::maximize() {
	GTK_Window::maximize();
}


void GTK_ViewWindow::unmaximize() {
	GTK_Window::unmaximize();
}

void GTK_ViewWindow::setPresenter(std::unique_ptr<IViewWindowPresenter> presenter) {
	presenter_=std::move(presenter);
}

IViewContainer& GTK_ViewWindow::getBasicViewContainer() {
	return *container_;
}

bool GTK_ViewWindow::isEmpty() const {
	return container_->isEmpty(true);
}

void GTK_ViewWindow::close() {
	GTK_Window::close();
}

IWindowPresenter& GTK_ViewWindow::getPresenter() {
	return *presenter_;
}

}//namespace erebus

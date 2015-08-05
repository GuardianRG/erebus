#include <gtk_view_window.h>

#include <string>
#include <memory>
#include <iostream>

#include <presenter/interfaces/i_view_window_presenter.h>
#include <presenter/interfaces/i_view_container_presenter.h>

#include <gtk_view_container.h>
#include <presenter/view_container_presenter.h>
#include <view/view_type.h>
#include <gtk_logger.h>

INIT_LOCATION;

namespace erebus  {
GTK_ViewWindow::GTK_ViewWindow(BaseObjectType* cobject,
                               const Glib::RefPtr<Gtk::Builder>& refBuilder
                              ):GTK_Window(cobject) {
	Gtk::Viewport *base;
	refBuilder->get_widget("basic_viewport",base);

	auto presenter=std::unique_ptr<IViewContainerPresenter>(
	                   std::make_unique<ViewContainerPresenter>()
	               );

	container_=Gtk::manage(new GTK_ViewContainer(
	                           base->get_hadjustment(),
	                           base->get_vadjustment(),
	                           nullptr)
	                      );

	presenter->setViewContainer(container_);
	container_->setPresenter(std::move(presenter));

	base->add(*container_);

	setPreferredSize(300,200);

	show_all_children();

	signal_hide().connect(sigc::mem_fun(*this,&GTK_ViewWindow::close) );

	BOOST_LOG_SEV(gtk_l::get(),
	              normal)<<LOCATION<<"Creating view window '"<<this<<"'";
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

std::string GTK_ViewWindow::classname() {
	return "GTK_ViewWindow";
}

void GTK_ViewWindow::setPresenter(std::unique_ptr<IViewWindowPresenter>
                                  presenter) {
	presenter_=std::move(presenter);
}

bool GTK_ViewWindow::containsWidget(std::size_t id) {
	return false;
}

IGUIObject* GTK_ViewWindow::getParentOf(std::size_t id) {
	return nullptr;
}

IViewContainer& GTK_ViewWindow::getBasicViewContainer() {
	return *container_;
}

bool GTK_ViewWindow::isEmpty() const {
	return true;//container_->isEmpty(true);
}

void GTK_ViewWindow::close() {
	BOOST_LOG_SEV(gtk_l::get(),
	              normal)<<LOCATION<<"Closing view window '"<<this<<"'";
	GTK_Window::close();
}

IWindowPresenter& GTK_ViewWindow::getPresenter() {
	return *presenter_;
}

}//namespace erebus

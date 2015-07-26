#include <gtk_main_window.h>

#include <memory>

#include <presenter/interfaces/i_main_window_presenter.h>
#include <presenter/interfaces/i_view_container_presenter.h>

#include <gtk_view_container.h>
#include <presenter/view_container_presenter.h>

namespace erebus {
GTK_MainWindow::GTK_MainWindow(BaseObjectType* cobject,
                               const Glib::RefPtr<Gtk::Builder>& refBuilder)
	: GTK_Window(cobject) {

	Gtk::Viewport *base;
	refBuilder->get_widget("base_view",base);

	auto presenter=std::unique_ptr<IViewContainerPresenter>(
	                   std::make_unique<ViewContainerPresenter>());

	basicView_=Gtk::manage(new GTK_ViewContainer(
	                           base->get_hadjustment(),
	                           base->get_vadjustment(),
	                           nullptr,
	                           nullptr));

	presenter->setViewContainer(basicView_);
	basicView_->setPresenter(std::move(presenter));

	base->add(*basicView_);

	show_all_children();

	signal_hide().connect(sigc::mem_fun(*this,&GTK_MainWindow::close) );

	Gtk::MenuItem* view_save;
	refBuilder->get_widget("view_save",view_save);
	view_save->signal_activate().
	connect(sigc::mem_fun(*this, &GTK_MainWindow::on_menu_view_save_click) );

	Gtk::MenuItem* view_show_tabs;
	refBuilder->get_widget("view_show_tabs",view_show_tabs);
	view_show_tabs->signal_activate().
	connect(sigc::mem_fun(*this, &GTK_MainWindow::on_menu_view_show_tabs_click));

}

GTK_MainWindow::~GTK_MainWindow() {

}

void GTK_MainWindow::on_menu_view_save_click() {
	presenter_->on_menu_view_save_click();
}

void GTK_MainWindow::on_menu_view_show_tabs_click() {
	presenter_->on_menu_view_show_tabs_click();
}

void GTK_MainWindow::setTitle(std::string title) {
	GTK_Window::setTitle(title);
}

std::string GTK_MainWindow::getTitle() const {
	return GTK_Window::getTitle();
}

void GTK_MainWindow::setPreferredSize(int width,int height) {
	GTK_Window::setPreferredSize(width,height);
}

void GTK_MainWindow::maximize() {
	GTK_Window::maximize();
}

void GTK_MainWindow::unmaximize() {
	GTK_Window::unmaximize();
}

void GTK_MainWindow::setPresenter(std::unique_ptr<IMainWindowPresenter> presenter) {
	presenter_=std::move(presenter);
}

void GTK_MainWindow::close() {
	Gtk::Window::close();
}

IWindowPresenter& GTK_MainWindow::getPresenter() {
	return *presenter_;
}

}//namespace erebus

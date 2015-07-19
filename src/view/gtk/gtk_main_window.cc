#include <gtk_main_window.h>

#include <presenter/interfaces/i_presenter.h>
#include <presenter/interfaces/i_main_window_presenter.h>

#include <gtk_view_container.h>
#include <presenter/view_container_presenter.h>

namespace erebus {

GTK_MainWindow::GTK_MainWindow() {

}

GTK_MainWindow::GTK_MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder): Gtk::Window(cobject) {
	Gtk::Viewport *base;
	refBuilder->get_widget("base_view",base);

	ViewContainerPresenter* presenter=new ViewContainerPresenter;
	basicView_=new GTK_ViewContainer(base->get_hadjustment(),base->get_vadjustment(),nullptr,nullptr);

	presenter->setViewContainer(basicView_);
	basicView_->setPresenter(presenter);

	base->add(*basicView_);

	show_all_children();
}

GTK_MainWindow::~GTK_MainWindow() {
	delete basicView_;
}

void GTK_MainWindow::setTitle(std::string title) {
	set_title(title);
}

std::string GTK_MainWindow::getTitle() {
	return get_title();
}

void GTK_MainWindow::setPreferredSize(int width,int height) {
	set_default_size(width,height);
}

void GTK_MainWindow::maximize() {
	Gtk::Window::maximize();
}

void GTK_MainWindow::unmaximize() {
	Gtk::Window::unmaximize();
}

void GTK_MainWindow::setPresenter(IPresenter* presenter) {
	presenter_=static_cast<IMainWindowPresenter*>(presenter);
}

}//namespace erebus

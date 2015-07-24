#include <gtk_main_window.h>

#include <memory>

#include <presenter/interfaces/i_main_window_presenter.h>

#include <gtk_view_container.h>
#include <presenter/view_container_presenter.h>

namespace erebus {
GTK_MainWindow::GTK_MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder): GTK_Window(cobject) {
	Gtk::Viewport *base;
	refBuilder->get_widget("base_view",base);

	auto presenter=std::unique_ptr<ViewContainerPresenter>(new ViewContainerPresenter);
	basicView_=new GTK_ViewContainer(base->get_hadjustment(),base->get_vadjustment(),nullptr,nullptr);

	presenter->setViewContainer(basicView_);
	basicView_->setPresenter(std::move(presenter));

	base->add(*basicView_);

	show_all_children();
}

GTK_MainWindow::~GTK_MainWindow() {
	delete basicView_;
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
	GTK_Window::close();
}

IWindowPresenter& GTK_MainWindow::getPresenter() {
	return *presenter_;
}

}//namespace erebus

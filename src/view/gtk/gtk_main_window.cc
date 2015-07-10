#include <gtk_main_window.h>

#include <presenter/interfaces/i_presenter.h>
#include <presenter/interfaces/i_main_window_presenter.h>
#include <presenter/view_presenter.h>

namespace erebus {

GTK_MainWindow::GTK_MainWindow() {
	
}
GTK_MainWindow::GTK_MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder): Gtk::Window(cobject){
	refBuilder->get_widget_derived("basic_viewport", basicViewport_);
	basicViewport_->setParent(nullptr);
	ViewPresenter* pres=new ViewPresenter;
	pres->setView(basicViewport_);
	pres->setParent(pres);
	basicViewport_->buildContextMenu();
	basicViewport_->setPresenter(pres);
}

GTK_MainWindow::~GTK_MainWindow() {
	
}

void GTK_MainWindow::setTitle(std::string title) {
	set_title(title);
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

	
}
#include <gtk_main_window.h>

namespace erebus {

GTK_MainWindow::GTK_MainWindow() {
	
}
GTK_MainWindow::GTK_MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder): Gtk::Window(cobject) {
	
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

	
}
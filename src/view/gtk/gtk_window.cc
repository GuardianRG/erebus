#include <gtk_window.h>

#include <string>

#include <presenter/interfaces/i_window_presenter.h>

namespace erebus {
GTK_Window::GTK_Window() {

}

GTK_Window::~GTK_Window() {

}

void GTK_Window::setTitle(std::string title) {
	set_title(title);
}

std::string GTK_Window::getTitle() const {
	return get_title();
}

void GTK_Window::setPreferredSize(int width,int height) {
	set_default_size(width,height);
}

void GTK_Window::maximize() {
	Gtk::Window::maximize();
}

void GTK_Window::unmaximize() {
	Gtk::Window::unmaximize();
}
}//namespace erebus

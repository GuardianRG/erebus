#include <gtk_window.h>

#include <string>

#include <presenter/interfaces/i_presenter.h>
#include <presenter/interfaces/i_window_presenter.h>

namespace erebus {
GTK_Window::GTK_Window() {

}

GTK_Window::~GTK_Window() {
	delete presenter_;
}

void GTK_Window::setTitle(std::string title) {
	set_title(title);
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

void GTK_Window::setPresenter(IPresenter* presenter) {
	presenter_=static_cast<IWindowPresenter*>(presenter);
}
}//namespace erebus

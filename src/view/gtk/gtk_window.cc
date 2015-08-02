#include <gtk_window.h>

#include <string>

#include <presenter/interfaces/i_window_presenter.h>

#include <view/interfaces/i_gui_manager.h>
#include <gtk_logger.h>

INIT_LOCATION;

namespace erebus {
GTK_Window::GTK_Window(BaseObjectType* cobject):Gtk::Window(cobject) {

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


void GTK_Window::setGUIManager(IGUIManager* manager) {
	guiManager_=manager;
}

void GTK_Window::unmaximize() {
	Gtk::Window::unmaximize();
}

void GTK_Window::close() {
	//BOOST_LOG_SEV(gtk_l::get(),normal)<<LOCATION<<"Closing window '"<<this<<"'";
	Gtk::Window::close();
	//GUIManager::getInstance().deleteWindow(this);
}
}//namespace erebus

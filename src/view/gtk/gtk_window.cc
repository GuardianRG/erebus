#include <gtk_window.h>

#include <gtkmm/window.h>

#include <string>

#include <gtk_logger.h>
#include <gtk_window.h>
#include <gtk_gui_manager.h>

INIT_LOCATION;

namespace erebus {
class IGUIManager;
}

namespace erebus {

GTK_Window::GTK_Window(BaseObjectType* cobject):Gtk::Window(cobject) {
	BOOST_LOG_SEV(gtk_l::get(),normal)<<LOCATION<<"Constructing "<<classname()<<" '"<<getID()<<"'";

	guiManager_=nullptr;
}

GTK_Window::~GTK_Window() {
	BOOST_LOG_SEV(gtk_l::get(),normal)<<LOCATION<<"Destructing "<<classname()<<" '"<<getID()<<"'";
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


void GTK_Window::setGUIManager(IGUIManager& manager) {
	guiManager_=&manager;
}

IGUIManager& GTK_Window::getGUIManager() {
	LOG_ASSERT(gtk_l::get(),guiManager_!=nullptr);
	return *guiManager_;
}

void GTK_Window::unmaximize() {
	Gtk::Window::unmaximize();
}

std::size_t GTK_Window::getID() {
	return reinterpret_cast<std::size_t>(this);
}

std::string GTK_Window::classname() {
	return "GTK_Window";
}

void GTK_Window::close() {
	LOG_ASSERT(gtk_l::get(),guiManager_!=nullptr);

	BOOST_LOG_SEV(gtk_l::get(),normal)<<LOCATION<<"Closing window '"<<getID()<<"'";
	Gtk::Window::close();
	guiManager_->destroyWindow(*this);
}
}//namespace erebus

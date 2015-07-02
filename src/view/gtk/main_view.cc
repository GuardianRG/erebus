#include <gtkmm.h>

#include <boost/signals2.hpp>
#include <boost/function.hpp>

#include <main_view.h>

namespace erebus {
	MainView::MainView(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder) : Gtk::Window(cobject) {
	
	set_default_size(800,600);
}

MainView::~MainView() {

}


void MainView::on_menu_file_open() {

}

void MainView::on_menu_file_quit() {
	quit_();
}

void MainView::registerFunctionQuit(boost::function<void()> func) {
	quit_.connect(func);
}

void MainView::setPreferredSize(int width,int height) {
	set_default_size(width,height);
}

void MainView::setTitle(std::string title) {
	set_title(title);
}

}
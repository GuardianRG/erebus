#include <gtk_main_window.h>

#include <memory>

#include <presenter/interfaces/i_main_window_presenter.h>

#include <gtk_logger.h>
#include <gtk_view_container_factory.h>
#include <gtk_view_container.h>

INIT_LOCATION;

namespace erebus {
GTK_MainWindow::GTK_MainWindow(BaseObjectType* cobject,
                               const Glib::RefPtr<Gtk::Builder>& refBuilder)
	: GTK_Window(cobject) {

	Gtk::Viewport *base;
	refBuilder->get_widget("base_view",base);

	basicView_=std::move(GTK_ViewContainerFactory::createViewContainer(base->get_hadjustment(),
	                     base->get_vadjustment()));

	base->add(*(basicView_.get()));

	show_all_children();



	/*signal_hide().connect(sigc::mem_fun(*this,&GTK_MainWindow::close) );

	Gtk::MenuItem* view_save;
	refBuilder->get_widget("view_save",view_save);
	view_save->signal_activate().
	connect(sigc::mem_fun(*this, &GTK_MainWindow::on_menu_view_save_click) );

	Gtk::MenuItem* view_show_tabs;
	refBuilder->get_widget("view_show_tabs",view_show_tabs);
	view_show_tabs->signal_activate().
	connect(sigc::mem_fun(*this, &GTK_MainWindow::on_menu_view_show_tabs_click));*/

}

GTK_MainWindow::~GTK_MainWindow() {

}

/*void GTK_MainWindow::on_menu_view_save_click() {
	//presenter_->on_menu_view_save_click();
}

void GTK_MainWindow::on_menu_view_show_tabs_click() {
	//presenter_->on_menu_view_show_tabs_click();
}*/

void GTK_MainWindow::setPresenter(std::unique_ptr<IMainWindowPresenter>
                                  presenter) {
	presenter_=std::move(presenter);
}

void GTK_MainWindow::close() {
	GTK_Window::close();
}

std::string GTK_MainWindow::classname() {
	return "GTK_MainWindow";
}

IWindowPresenter& GTK_MainWindow::getPresenter() {
	return *presenter_;
}

}//namespace erebus

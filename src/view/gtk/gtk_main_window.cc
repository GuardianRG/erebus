#include <gtk_main_window.h>

#include <memory>

#include <gtkmm/viewport.h>

#include <presenter/interfaces/i_main_window_presenter.h>
#include <view/interfaces/i_gui_manager.h>

#include <gtk_logger.h>
#include <gtk_view_container_factory.h>
#include <gtk_view_container.h>

INIT_LOCATION;

namespace erebus {
GTK_MainWindow::GTK_MainWindow(BaseObjectType* cobject,
                               const Glib::RefPtr<Gtk::Builder>& refBuilder)
	: GTK_Window(cobject) {

	isInitialized_=false;
	
	base_=nullptr;
	refBuilder->get_widget("base_view",base_);
	LOG_ASSERT(gtk_l::get(),base_!=nullptr);
	
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

void GTK_MainWindow::initialize(IGUIManager& manager) {
	LOG_ASSERT(gtk_l::get(),!isInitialized_);
	
	setGUIManager(manager);
	
	
	basicView_=std::move(GTK_ViewContainerFactory::createViewContainer(manager,base_->get_hadjustment(),
									   base_->get_vadjustment()));
	
	base_->add(*(basicView_.get()));
	
	show_all_children();
	
	isInitialized_=true;
}

bool GTK_MainWindow::containsWidget(std::size_t id) {
	LOG_ASSERT(gtk_l::get(),isInitialized_);
	
	if(id==getID())
		return true;
	
	return basicView_->containsWidget(id);
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
	LOG_ASSERT(gtk_l::get(),isInitialized_);
	GTK_Window::close();
}

std::string GTK_MainWindow::classname() {
	return "GTK_MainWindow";
}

IWindowPresenter& GTK_MainWindow::getPresenter() {
	return *presenter_;
}

}//namespace erebus

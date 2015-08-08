#include <gtk_main_window.h>

#include <memory>

#include <gtkmm/viewport.h>

#include <presenter/interfaces/i_main_window_presenter.h>
#include <view/interfaces/i_gui_manager.h>

#include <gtk_logger.h>
#include <gtk_view_container_factory.h>
#include <gtk_view_container.h>
#include <view_container_presenter.h>

INIT_LOCATION;

namespace erebus {

const std::string GTK_MainWindow::CLASSNAME="GTK_MainWindow";

GTK_MainWindow::GTK_MainWindow(BaseObjectType* cobject,
                               const Glib::RefPtr<Gtk::Builder>& refBuilder)
	: GTK_Window(cobject) {

	LOG_CONSTRUCTOR;

	isInitialized_=false;

	base_=nullptr;
	refBuilder->get_widget("base_view",base_);
	LOG_ASSERT(gtk_l::get(),base_!=nullptr);

	Gtk::MenuItem* view_save;
	refBuilder->get_widget("view_new_window",view_save);
	view_save->signal_activate().
	connect(sigc::mem_fun(*this, &GTK_MainWindow::on_menu_view_new_window_click) );


	show_all_children();



	/*signal_hide().connect(sigc::mem_fun(*this,&GTK_MainWindow::close) );



	Gtk::MenuItem* view_show_tabs;
	refBuilder->get_widget("view_show_tabs",view_show_tabs);
	view_show_tabs->signal_activate().
	connect(sigc::mem_fun(*this, &GTK_MainWindow::on_menu_view_show_tabs_click));*/

}

GTK_MainWindow::~GTK_MainWindow() {
	LOG_DESTRUCTOR;
}

IGUIObject* GTK_MainWindow::getParentOf(std::size_t id) {
	if(!containsWidget(id))
		return nullptr;

	LOG_ASSERT(gtk_l::get(),isInitialized_);
	LOG_ASSERT(gtk_l::get(),basicViewContainer_.get()!=nullptr);

	if(basicViewContainer_->getID()==id)
		return this;
	return basicViewContainer_->getParentOf(id);
}

void GTK_MainWindow::on_menu_view_new_window_click() {
	LOG_ASSERT(gtk_l::get(),presenter_.get()!=nullptr);

	presenter_->on_menu_view_new_window_click();
}

void GTK_MainWindow::initialize(IGUIManager& manager) {
	LOG_ASSERT(gtk_l::get(),!isInitialized_);

	setGUIManager(manager);


	basicViewContainer_=std::move(GTK_ViewContainerFactory::template
	                              createViewContainer<ViewContainerPresenter>
	                              (manager,
	                               base_->get_hadjustment(),
	                               base_->get_vadjustment()));

	base_->add(*(basicViewContainer_.get()));

	show_all_children();

	isInitialized_=true;
}

bool GTK_MainWindow::containsWidget(std::size_t id) {
	LOG_ASSERT(gtk_l::get(),isInitialized_);
	LOG_ASSERT(gtk_l::get(),basicViewContainer_.get()!=nullptr);

	if(basicViewContainer_->getID()==id)
		return true;

	return basicViewContainer_->containsWidget(id);
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


std::string GTK_MainWindow::classname() {
	return CLASSNAME;
}


}//namespace erebus

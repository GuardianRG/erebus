#include <gtk_main_window.h>

#include <gtkmm/viewport.h>
#include <gtkmm/builder.h>
#include <glibmm/refptr.h>

#include <memory>

#include <i_main_window_presenter.h>
#include <i_gui_manager.h>

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
	refBuilder->get_widget("basic_viewport",base_);
	LOG_ASSERT_GTK(base_!=nullptr);

	Gtk::MenuItem* view_new_windo;
	refBuilder->get_widget("view_new_window",view_new_windo);
	view_new_windo->signal_activate().
	connect(sigc::mem_fun(*this, &GTK_MainWindow::on_menu_view_new_window_click) );
	
	Gtk::MenuItem* view_save_preferences;
	refBuilder->get_widget("view_save_preferences",view_save_preferences);
	view_save_preferences->signal_activate().
	connect(sigc::mem_fun(*this, &GTK_MainWindow::on_menu_view_save_preferences_click) );
	
	Gtk::MenuItem* view_restore_defaults;
	refBuilder->get_widget("view_restore_defaults",view_restore_defaults);
	view_restore_defaults->signal_activate().
	connect(sigc::mem_fun(*this, &GTK_MainWindow::on_menu_view_restore_defaults_click) );

	show_all_children();
}

GTK_MainWindow::~GTK_MainWindow() {
	LOG_DESTRUCTOR;
}

void GTK_MainWindow::on_menu_view_restore_defaults_click() {
	LOG_ASSERT_GTK(isInitialized_);
	LOG_ASSERT_GTK(presenter_.get()!=nullptr);
	
	presenter_->on_menu_view_restore_defaults_click();
}

IGUIObject* GTK_MainWindow::getParentOf(std::size_t id) {
	LOG_ASSERT_GTK(isInitialized_);
	
	if(!containsWidget(id))
		return nullptr;

	LOG_ASSERT_GTK(basicViewContainer_.get()!=nullptr);

	if(basicViewContainer_->getID()==id)
		return this;
	return basicViewContainer_->getParentOf(id);
}

void GTK_MainWindow::on_menu_view_new_window_click() {
	LOG_ASSERT_GTK(isInitialized_);
	LOG_ASSERT_GTK(presenter_.get()!=nullptr);

	presenter_->on_menu_view_new_window_click();
}

void GTK_MainWindow::initialize(IGUIManager& manager) {
	LOG_ASSERT_GTK(!isInitialized_);

	setGUIManager(manager);

	basicViewContainer_=std::move(GTK_ViewContainerFactory::createViewContainer<ViewContainerPresenter>
	                              (manager,
	                               base_->get_hadjustment(),
	                               base_->get_vadjustment()));

	base_->add(*(basicViewContainer_.get()));

	show_all_children();

	isInitialized_=true;
}

void GTK_MainWindow::on_menu_view_save_preferences_click() {
	LOG_ASSERT_GTK(presenter_.get()!=nullptr);
	LOG_ASSERT_GTK(isInitialized_);
	
	presenter_->on_menu_view_save_preferences_click();
}

bool GTK_MainWindow::containsWidget(std::size_t id) {
	LOG_ASSERT_GTK(isInitialized_);
	LOG_ASSERT_GTK(basicViewContainer_.get()!=nullptr);

	if(basicViewContainer_->getID()==id)
		return true;

	return basicViewContainer_->containsWidget(id);
}

void GTK_MainWindow::setPresenter(std::unique_ptr<IMainWindowPresenter>
                                  presenter) {
	presenter_=std::move(presenter);
}

std::string GTK_MainWindow::classname() {
	return CLASSNAME;
}


}//namespace erebus

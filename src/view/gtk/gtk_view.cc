#include <gtk_view.h>

#include <gtkmm/menu.h>
#include <gtkmm/menuitem.h>
#include <gtkmm/builder.h>
#include <glibmm/refptr.h>
#include <gtkmm/viewport.h>

#include <memory>
#include <string>

#include <view/interfaces/i_view.h>
#include <view/interfaces/i_gui_manager.h>
#include <presenter/interfaces/i_view_presenter.h>
#include <gtk_logger.h>

INIT_LOCATION;

namespace erebus {

GTK_View::GTK_View(BaseObjectType* cobject): Gtk::Viewport(cobject) {

	title_="";
	guiManager_=nullptr;
	
}

GTK_View::~GTK_View() {

}

void GTK_View::setTitle(const std::string& title) {
	title_=title;
}

void GTK_View::setGUIManager(IGUIManager& manager) {
	guiManager_=&manager;
}

std::unique_ptr<Gtk::Menu> GTK_View::createContextMenu() {
	auto contextMenu=std::make_unique<Gtk::Menu>();
	
	auto emptyItem=new Gtk::MenuItem("(no entries)");
	emptyItem->set_sensitive(false);
	
	contextMenu->append(*emptyItem);
	
	return std::move(contextMenu);
}

std::string GTK_View::getTitle() const {
	return title_;
}

IGUIManager& GTK_View::getGUIManager() {
	LOG_ASSERT(gtk_l::get(),guiManager_!=nullptr);

	return *guiManager_;
}

}//namespace erebus

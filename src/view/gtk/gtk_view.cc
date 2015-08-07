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

GTK_View::GTK_View(BaseObjectType* cobject,
                   const Glib::RefPtr<Gtk::Builder>& refBuilder): Gtk::Viewport(cobject) {

	/*	add_events(Gdk::BUTTON_PRESS_MASK );

	#ifndef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
		signal_button_press_event().
		connect(sigc::mem_fun(*this, &GTK_View::on_button_press_event), false);
	#endif
		signal_parent_changed().
		connect(sigc::mem_fun(*this, &GTK_View::on_my_parent_changed), false);
	*/

	title_="";
	guiManager_=nullptr;
	/*	parent_=nullptr;
		popupMenu_=std::make_unique<Gtk::Menu>();*/
}

GTK_View::~GTK_View() {

}

/*void GTK_View::on_my_parent_changed(Gtk::Widget* previous_parent) {
	if(get_parent()!=nullptr) {
		if(get_parent()->get_parent()!=nullptr) {
			auto buffer=dynamic_cast<GTK_ViewContainer*>(get_parent()->get_parent());
			assert(buffer!=0);
			setParent(buffer);
			createContextMenu();
		}
	}
}*/
void GTK_View::setTitle(std::string title) {
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

/*void GTK_View::setParent(IViewContainer* container) {
	parent_=container;
}

IViewContainer* GTK_View::getParent() const {
	return parent_;
}

bool GTK_View::on_button_press_event(GdkEventButton *ev) {
	bool return_value = false;

	return_value = Viewport::on_button_press_event(ev);
	guiManager_->showMessageDialog(getID(),"TEST","TEST",ErrorLevel::INFO);

	if( (ev->type == GDK_BUTTON_PRESS)) {
		switch(ev->button) {
		case 3:
			timeBuffer_=ev->time;
			clickBuffer_=3;
			getPresenter().on_right_button_click();
			break;
		case 1:
			timeBuffer_=ev->time;
			clickBuffer_=1;
			getPresenter().on_left_button_click();
			break;
		default:
			;
		};

	}
	return return_value;
}

void GTK_View::close() {

}

void GTK_View::popOut() {

}

void GTK_View::on_context_menu_close_click() {
	getPresenter().on_context_menu_close_click();
}

void GTK_View::on_context_menu_pop_out_click() {
	getPresenter().on_context_menu_pop_out_click();
}

void GTK_View::createContextMenu() {
	assert( parent_!=nullptr);

	popupMenu_=std::unique_ptr<Gtk::Menu>(new Gtk::Menu);

	auto view=Gtk::manage(new Gtk::MenuItem("View"));
	auto view_menu=Gtk::manage(new Gtk::Menu);
	view->set_submenu(*view_menu);

	auto sep=Gtk::manage(new Gtk::SeparatorMenuItem);
	auto pop_out = Gtk::manage(new Gtk::MenuItem("Pop out"));
	auto close = Gtk::manage(new Gtk::MenuItem("Close view"));

	close->signal_activate().
	connect(sigc::mem_fun(*this, &GTK_View::on_context_menu_close_click) );
	pop_out->signal_activate().
	connect(sigc::mem_fun(*this, &GTK_View::on_context_menu_pop_out_click) );

	popupMenu_->append(*sep);
	view_menu->append(*pop_out);
	view_menu->append(*close);
	view_menu->accelerate(*this);
	popupMenu_->append(*view);


	popupMenu_->accelerate(*this);
	popupMenu_->show_all();
}
void GTK_View::showContextMenu() {
	assert(popupMenu_.get()!=nullptr);

	popupMenu_->popup(clickBuffer_,timeBuffer_);
}*/

}//namespace erebus

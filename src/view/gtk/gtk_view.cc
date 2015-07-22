#include <gtk_view.h>

#include <gtkmm.h>

#include <assert.h>
#include <iostream>

#include <view/interfaces/i_view.h>
#include <presenter/interfaces/i_view_presenter.h>
#include <view/gui_manager.h>

namespace erebus {

GTK_View::GTK_View(Glib::RefPtr<Gtk::Adjustment> h_adjustment,Glib::RefPtr<Gtk::Adjustment> v_adjustment):Gtk::Viewport(h_adjustment,v_adjustment) {
	init();
}

GTK_View::GTK_View(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder): Gtk::Viewport(cobject) {
	init();
}

GTK_View::~GTK_View() {

}


void GTK_View::init() {

	add_events(Gdk::BUTTON_PRESS_MASK );

#ifndef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
	signal_button_press_event().connect(sigc::mem_fun(*this, &GTK_View::on_button_press_event), false);
#endif
	signal_parent_changed().connect(sigc::mem_fun(*this, &GTK_View::on_my_parent_changed), false);


	title_="";
	container_=nullptr;
	popupMenu_=nullptr;
}

void GTK_View::on_my_parent_changed(Gtk::Widget* previous_parent) {
	if(get_parent()!=nullptr) {
		if(get_parent()->get_parent()!=nullptr) {
			setParent(dynamic_cast<GTK_ViewContainer*>(get_parent()->get_parent()));
			createContextMenu();
		}
	}
}
void GTK_View::setTitle(std::string title) {
	title_=title;
}

std::string GTK_View::getTitle() {
	return title_;
}

void GTK_View::setParent(IViewContainer* container) {
	container_=container;
}

IViewContainer* GTK_View::getParent() {
	return container_;
}

bool GTK_View::on_button_press_event(GdkEventButton *ev) {
	bool return_value = false;

	return_value = Viewport::on_button_press_event(ev);

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
	assert( container_!=nullptr && "No view container set for GTK_View");

	container_->closeView(this);
}

void GTK_View::popOut() {
	assert( container_!=nullptr && "No view container set for GTK_View");

	container_->popOutView(this);
}

void GTK_View::on_context_menu_close_click() {
	getPresenter().on_context_menu_close_click();
}

void GTK_View::on_context_menu_pop_out_click() {
	getPresenter().on_context_menu_pop_out_click();
}

void GTK_View::createContextMenu() {
	assert( container_!=nullptr && "No view container set for GTK_View");

	delete popupMenu_;
	popupMenu_=new Gtk::Menu;

	Gtk::MenuItem* view=Gtk::manage(new Gtk::MenuItem("View"));
	Gtk::Menu* view_menu=Gtk::manage(new Gtk::Menu);
	view->set_submenu(*view_menu);

	Gtk::SeparatorMenuItem* sep=Gtk::manage(new Gtk::SeparatorMenuItem);
	Gtk::MenuItem* pop_out = Gtk::manage(new Gtk::MenuItem("Pop out"));
	Gtk::MenuItem* close = Gtk::manage(new Gtk::MenuItem("Close view"));

	close->signal_activate().connect(sigc::mem_fun(*this, &GTK_View::on_context_menu_close_click) );
	pop_out->signal_activate().connect(sigc::mem_fun(*this, &GTK_View::on_context_menu_pop_out_click) );

	popupMenu_->append(*sep);
	view_menu->append(*pop_out);
	view_menu->append(*close);
	view_menu->accelerate(*this);
	popupMenu_->append(*view);

	static_cast<GTK_ViewContainer*>(container_)->buildContextMenu(popupMenu_);

	popupMenu_->accelerate(*this);
	popupMenu_->show_all();
}
void GTK_View::showContextMenu() {
	assert(popupMenu_!=nullptr&&"No popup menu set for GTK_View");

	popupMenu_->popup(clickBuffer_,timeBuffer_);
}

}//namespace erebus

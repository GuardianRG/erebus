#include <gtk_view.h>

#include <gtkmm.h>

#include <assert.h>
#include <iostream>

#include <view/interfaces/i_view.h>
#include <presenter/interfaces/i_presenter.h>
#include <presenter/interfaces/i_view_presenter.h>


namespace erebus {

GTK_View::GTK_View(Glib::RefPtr<Gtk::Adjustment> h_adjustment,Glib::RefPtr<Gtk::Adjustment> v_adjustment):Gtk::Viewport(h_adjustment,v_adjustment) {
	init();
}

GTK_View::GTK_View(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder): Gtk::Viewport(cobject) {
	init();
}

GTK_View::~GTK_View() {
	delete popupMenu_;
}


void GTK_View::init() {

	add_events(Gdk::BUTTON_PRESS_MASK );

#ifndef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
	signal_button_press_event().connect(sigc::mem_fun(*this, &GTK_View::on_button_press_event), false);
#endif
	signal_parent_changed().connect(sigc::mem_fun(*this, &GTK_View::on_my_parent_changed), false);


	title_="";
	presenter_=nullptr;
	container_=nullptr;
	popupMenu_=nullptr;
}

void GTK_View::on_my_parent_changed(Gtk::Widget* previous_parent) {
	if(get_parent()!=nullptr) {
		if(get_parent()->get_parent()!=nullptr) {
			setViewContainer(dynamic_cast<GTK_ViewContainer*>(get_parent()->get_parent()));
			createContextMenu();
		}
	}
}

void GTK_View::setPresenter(IPresenter* presenter) {
	presenter_=static_cast<IViewPresenter*>(presenter);
}
void GTK_View::setTitle(std::string title) {
	title_=title;
}

std::string GTK_View::getTitle() {
	return title_;
}


void GTK_View::setViewContainer(IViewContainer* container) {
	container_=static_cast<GTK_ViewContainer*>(container);
}

bool GTK_View::on_button_press_event(GdkEventButton *ev) {
	assert( presenter_!=nullptr && "No presenter set for GTK_View");

	bool return_value = false;

	return_value = Viewport::on_button_press_event(ev);

	if( (ev->type == GDK_BUTTON_PRESS)) {
		switch(ev->button) {
		case 3:
			timeBuffer_=ev->time;
			clickBuffer_=3;
			presenter_->on_right_button_click();
			break;
		case 1:
			timeBuffer_=ev->time;
			clickBuffer_=1;
			presenter_->on_left_button_click();
			break;
		default:
			;
		};

	}
	return return_value;
}

IViewContainer* GTK_View::getViewContainer() {
	return container_;
}


void GTK_View::createContextMenu() {
	assert( container_!=nullptr && "No view container set for GTK_View");

	delete popupMenu_;
	popupMenu_=new Gtk::Menu;

	container_->buildContextMenu(popupMenu_);

	popupMenu_->accelerate(*this);
	popupMenu_->show_all();
}
void GTK_View::showContextMenu() {
	assert(popupMenu_!=nullptr&&"No popup menus et for GTK_View");

	popupMenu_->popup(clickBuffer_,timeBuffer_);
}
}//namespace erebus
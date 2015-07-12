#include <gtkmm.h>

#include <gtk_view_container.h>
#include <gtk_view.h>
#include <presenter/interfaces/i_view_container_presenter.h>
#include <presenter/view_container_presenter.h>
#include <iostream>

namespace erebus {

GTK_ViewContainer::GTK_ViewContainer(Gtk::Viewport &vp,Gtk::Notebook* notebook): Gtk::Viewport(vp.get_hadjustment(),vp.get_vadjustment()),parent_(vp) {
	if(notebook==nullptr)
		notebook_=new Gtk::Notebook;
	else
		notebook_=notebook;

	add(*notebook_);

	show_all_children();

	add_events(Gdk::BUTTON_PRESS_MASK );

#ifndef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
	signal_button_press_event().connect(sigc::mem_fun(*this, &GTK_ViewContainer::on_button_press_event), false);
#endif

	Gtk::SeparatorMenuItem* sep=Gtk::manage(new Gtk::SeparatorMenuItem);
	Gtk::MenuItem* split_h = Gtk::manage(new Gtk::MenuItem("Split horizontal"));
	Gtk::MenuItem* split_v = Gtk::manage(new Gtk::MenuItem("Split vertical"));
	Gtk::MenuItem* add_view = Gtk::manage(new Gtk::MenuItem("Add View"));

	split_h->signal_activate().connect(sigc::mem_fun(*this, &GTK_ViewContainer::on_context_menu_split_view_horizontal_click) );
	split_v->signal_activate().connect(sigc::mem_fun(*this, &GTK_ViewContainer::on_context_menu_split_view_vertical_click) );




	popupMenu_.append(*sep);
	popupMenu_.append(*split_h);
	popupMenu_.append(*split_v);
	popupMenu_.append(*add_view);
	/*Gtk::Menu* submenu=Gtk::manage(new Gtk::Menu);

	Gtk::MenuItem* split_view_item = Gtk::manage(new Gtk::MenuItem("Split view"));
	split_view_item->signal_activate().connect(
		sigc::mem_fun(*this, &GTK_View::on_popup_menu_view_split_view_click) );

	submenu->append(*split_view_item);

	base_item->set_submenu(*submenu);

	addContextMenuItem(*base_item);*/

	popupMenu_.accelerate(*this);
	popupMenu_.show_all();


}

GTK_ViewContainer::~GTK_ViewContainer() {

}
bool GTK_ViewContainer::isTopLevelContainer() {
	return !(notebook_==nullptr);
}

void GTK_ViewContainer::on_context_menu_split_view_horizontal_click() {
	presenter_->on_context_menu_split_view_horizontal_click();
}
void GTK_ViewContainer::on_context_menu_split_view_vertical_click() {
	presenter_->on_context_menu_split_view_vertical_click();
}
void GTK_ViewContainer::showContextMenu() {
	popupMenu_.popup(3,buffer_);
}
bool GTK_ViewContainer::on_button_press_event(GdkEventButton* event) {
	bool return_value = false;

	return_value = Viewport::on_button_press_event(event);

	if( (event->type == GDK_BUTTON_PRESS)) {
		switch(event->button) {
		case 3:
			buffer_=event->time;
			presenter_->on_right_button_click();
			break;
		case 1:
			buffer_=event->time;
			presenter_->on_left_button_click();
			break;
		default:
			;
		};

	}

	return return_value;
}


void GTK_ViewContainer::setPresenter(IViewContainerPresenter* presenter) {
	presenter_=presenter;
}

void GTK_ViewContainer::split() {
	Gtk::Container::remove(*notebook_);

	GTK_ViewContainer* vc1=new GTK_ViewContainer(parent_,notebook_);
	GTK_ViewContainer* vc2=new GTK_ViewContainer(parent_,nullptr);

	ViewContainerPresenter* vcp1=new ViewContainerPresenter;
	ViewContainerPresenter* vcp2=new ViewContainerPresenter;

	vcp1->setView(vc1);
	vcp2->setView(vc2);

	vc1->setPresenter(vcp1);
	vc2->setPresenter(vcp2);

	paned_->add1(*vc1);
	paned_->add2(*vc2);


	//if set to -1 the whole system will crash.
	paned_->set_border_width(0);

	add(*paned_);

	notebook_=nullptr;

	show_all_children();
}

void GTK_ViewContainer::splitHorizontal() {

	paned_=new Gtk::Paned( Gtk::ORIENTATION_HORIZONTAL);
	Gdk::Rectangle rec=get_allocation();
	paned_->set_position(rec.get_width()/2);

	split();
}
void GTK_ViewContainer::splitVertical() {

	paned_=new Gtk::Paned( Gtk::ORIENTATION_VERTICAL);
	Gdk::Rectangle rec=get_allocation();
	paned_->set_position(rec.get_height()/2);

	split();
}

void GTK_ViewContainer::showTabs(bool showTabs) {
	notebook_->set_show_tabs(showTabs);
}

}
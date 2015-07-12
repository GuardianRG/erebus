#include <gtkmm.h>

#include <gtk_view_container.h>
#include <gtk_view.h>
#include <presenter/interfaces/i_view_container_presenter.h>
#include <presenter/view_container_presenter.h>
#include <iostream>
#include <gtk_empty_view.h>
#include <view/view_type.h>
#include <view/interfaces/i_empty_view.h>
#include <presenter/interfaces/i_empty_view_presenter.h>
#include <presenter/empty_view_presenter.h>

namespace erebus {

GTK_ViewContainer::GTK_ViewContainer(Glib::RefPtr<Gtk::Adjustment> h_adjustment,Glib::RefPtr<Gtk::Adjustment> v_adjustment,Gtk::Notebook* notebook): Gtk::Viewport(h_adjustment,v_adjustment),h_adjustment_(h_adjustment),v_adjustment_(v_adjustment) {

	if(notebook==nullptr) {
		notebook_=new Gtk::Notebook;
		showTabs(false);
	}
	else
		notebook_=notebook;

	add(*notebook_);

	

	add_events(Gdk::BUTTON_PRESS_MASK );

#ifndef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
	signal_button_press_event().connect(sigc::mem_fun(*this, &GTK_ViewContainer::on_button_press_event), false);
#endif

	popupMenu_=new Gtk::Menu;
	
	
	buildContextMenu(popupMenu_);

	popupMenu_->accelerate(*this);
	popupMenu_->show_all();

	show_all_children();
}

GTK_ViewContainer::~GTK_ViewContainer() {

}
bool GTK_ViewContainer::isEmpty() {
	return notebook_==nullptr||notebook_->get_n_pages()==0;
}

void GTK_ViewContainer::on_context_menu_split_view_horizontal_click() {
	presenter_->on_context_menu_split_view_horizontal_click();
}
void GTK_ViewContainer::on_context_menu_split_view_vertical_click() {
	presenter_->on_context_menu_split_view_vertical_click();
}
void GTK_ViewContainer::showContextMenu() {
	popupMenu_->popup(3,buffer_);
}
void GTK_ViewContainer::buildContextMenu(Gtk::Menu* menu) {
	Gtk::SeparatorMenuItem* sep=Gtk::manage(new Gtk::SeparatorMenuItem);
	Gtk::MenuItem* split_h = Gtk::manage(new Gtk::MenuItem("Split horizontal"));
	Gtk::MenuItem* split_v = Gtk::manage(new Gtk::MenuItem("Split vertical"));
	Gtk::MenuItem* add_view = Gtk::manage(new Gtk::MenuItem("Add View"));
	
	split_h->signal_activate().connect(sigc::mem_fun(*this, &GTK_ViewContainer::on_context_menu_split_view_horizontal_click) );
	split_v->signal_activate().connect(sigc::mem_fun(*this, &GTK_ViewContainer::on_context_menu_split_view_vertical_click) );
	
	Gtk::Menu* view_menu=Gtk::manage(new Gtk::Menu);
	  
	 Gtk::MenuItem* empty_view = Gtk::manage(new Gtk::MenuItem("Empty View"));
	 empty_view->signal_activate().connect(sigc::mem_fun(*this, &GTK_ViewContainer::on_context_menu_add_view_empty_view_click) );
		 
		 view_menu->append(*empty_view);
		 
		add_view->set_submenu(*view_menu);
	
	
	menu->append(*sep);
	menu->append(*split_h);
	menu->append(*split_v);
	menu->append(*add_view);
	
	
	
}
void GTK_ViewContainer::on_context_menu_add_view_empty_view_click() {
	presenter_->on_context_menu_add_view_click(ViewType::EMPTY_VIEW);
}

void GTK_ViewContainer::setPresenter(IViewContainerPresenter* presenter) {
	presenter_=presenter;
}
bool GTK_ViewContainer::on_button_press_event(GdkEventButton *ev) {
	bool return_value = false;
	return_value = Viewport::on_button_press_event(ev);
	
	if( (ev->type == GDK_BUTTON_PRESS)) {
		switch(ev->button) {
			case 3:
				buffer_=ev->time;
				presenter_->on_right_button_click();
				break;
			case 1:
				buffer_=ev->time;
				presenter_->on_left_button_click();
				break;
			default:
				;
		};
		
	}
	return return_value;
}
bool GTK_ViewContainer::isTopLevel() {
	return notebook_!=nullptr;
}
void GTK_ViewContainer::split() {
	Gtk::Container::remove(*notebook_);

	GTK_ViewContainer* vc1=new GTK_ViewContainer(get_hadjustment(),get_vadjustment(),notebook_);
	GTK_ViewContainer* vc2=new GTK_ViewContainer(get_hadjustment(),get_vadjustment(),nullptr);

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

void GTK_ViewContainer::addView(ViewType type) {
	switch(type) {
		case ViewType::EMPTY_VIEW:
		{
			GTK_EmptyView* ev=new GTK_EmptyView(h_adjustment_,v_adjustment_);
			ev->setTitle("TEST");
			ev->setViewContainer(this);
			ev->createContextMenu();
			EmptyViewPresenter* p=new EmptyViewPresenter;
			p->setView(ev);
			ev->setPresenter(p);
			addView(ev);
			break;
		}
		default:;
	}
}
void GTK_ViewContainer::addView(IView* view) {
	if(notebook_->get_n_pages()>=1)
		showTabs(true);
	notebook_->append_page(*(dynamic_cast<GTK_View*>(view)),view->getTitle());
	
	show_all_children();
}

void GTK_ViewContainer::showTabs(bool showTabs) {
	notebook_->set_show_tabs(showTabs);
}

}
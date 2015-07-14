#include <gtk_view_container.h>

#include <gtkmm.h>

#include <assert.h>
#include <iterator>

#include <presenter/interfaces/i_view_container_presenter.h>

#include <presenter/view_container_presenter.h>
#include <view/view_type.h>
#include <gtk_view_builder.h>

namespace erebus {

GTK_ViewContainer::GTK_ViewContainer(
    Glib::RefPtr<Gtk::Adjustment> h_adjustment,
    Glib::RefPtr<Gtk::Adjustment> v_adjustment,
    Gtk::Notebook* notebook):
	Gtk::Viewport(h_adjustment,v_adjustment),
	h_adjustment_(h_adjustment),
	v_adjustment_(v_adjustment) {

	if(notebook==nullptr) {
		notebook_=new Gtk::Notebook;
		notebook_->set_group_name("notebooks");
		showTabs(true);
	} else {
		notebook_=notebook;

		//Rebind the function pointers of the context menu
		for(auto w:notebook->get_children()) {
			GTK_View* buffer=dynamic_cast<GTK_View*>(w);
			buffer->setViewContainer(this);
			buffer->createContextMenu();
		}

	}

	notebook_->set_scrollable(true);

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

	isSplit_=false;
	paned_=nullptr;
}

GTK_ViewContainer::~GTK_ViewContainer() {
	delete notebook_;
	delete paned_;
	delete popupMenu_;
}
bool GTK_ViewContainer::isEmpty() {
	return notebook_==nullptr||notebook_->get_n_pages()==0;
}


void GTK_ViewContainer::on_context_menu_split_horizontal_click() {
	assert( presenter_!=nullptr && "No presenter set for GTK_ViewContainer");

	presenter_->on_context_menu_split_horizontal_click();
}

void GTK_ViewContainer::on_context_menu_split_vertical_click() {
	assert( presenter_!=nullptr && "No presenter set for GTK_ViewContainer");

	presenter_->on_context_menu_split_vertical_click();
}

void GTK_ViewContainer::showContextMenu() {
	assert( popupMenu_!=nullptr && "No popup menu set for GTK_ViewContainer");

	popupMenu_->popup(clickBuffer_,timeBuffer_);
}

void GTK_ViewContainer::buildContextMenu(Gtk::Menu* menu) {
	Gtk::SeparatorMenuItem* sep=Gtk::manage(new Gtk::SeparatorMenuItem);

	Gtk::MenuItem* join=Gtk::manage(new Gtk::MenuItem("Join"));
	Gtk::MenuItem* split=Gtk::manage(new Gtk::MenuItem("Split"));
	Gtk::MenuItem* add_view = Gtk::manage(new Gtk::MenuItem("Add View"));

	join->signal_activate().connect(sigc::mem_fun(*this, &GTK_ViewContainer::on_context_menu_join_click) );

	Gtk::Menu* split_menu=Gtk::manage(new Gtk::Menu);

	Gtk::MenuItem* split_h = Gtk::manage(new Gtk::MenuItem("Horizontal"));
	Gtk::MenuItem* split_v = Gtk::manage(new Gtk::MenuItem("Vertical"));

	split_h->signal_activate().connect(sigc::mem_fun(*this, &GTK_ViewContainer::on_context_menu_split_horizontal_click) );
	split_v->signal_activate().connect(sigc::mem_fun(*this, &GTK_ViewContainer::on_context_menu_split_vertical_click) );

	split_menu->append(*split_h);
	split_menu->append(*split_v);

	split->set_submenu(*split_menu);

	Gtk::Menu* view_menu=Gtk::manage(new Gtk::Menu);

	Gtk::MenuItem* empty_view = Gtk::manage(new Gtk::MenuItem("Empty View"));

	empty_view->signal_activate().connect(sigc::mem_fun(*this, &GTK_ViewContainer::on_context_menu_add_view_empty_view_click) );

	view_menu->append(*empty_view);

	add_view->set_submenu(*view_menu);


	menu->append(*sep);
	menu->append(*join);
	menu->append(*split);
	menu->append(*add_view);

}

void GTK_ViewContainer::joinContainer() {
	if(!isSplit_)
		return;

	GTK_ViewContainer* container1=dynamic_cast<GTK_ViewContainer*>(paned_->get_child1());
	GTK_ViewContainer* container2=dynamic_cast<GTK_ViewContainer*>(paned_->get_child2());

	if(!container1->isTopLevel()) {
		container1->joinContainer();
	}
	if(!container2->isTopLevel()) {
		container2->joinContainer();
	}

	notebook_=new Gtk::Notebook;
	notebook_->set_group_name("notebooks");

	auto children=container1->notebook_->get_children();
	auto it=std::begin(children);


	while (it != std::end(children)) {
		GTK_View* buffer=dynamic_cast<GTK_View*>(*it);

		container1->notebook_->remove_page(**it);

		buffer->setViewContainer(this);
		buffer->createContextMenu();
		notebook_->append_page(*buffer,buffer->getTitle());
		notebook_->set_tab_reorderable(*buffer);
		notebook_->set_tab_detachable(*buffer);

		++it;
	}



	children=container2->notebook_->get_children();
	it=std::begin(children);

	while (it != std::end(children)) {
		GTK_View* buffer=dynamic_cast<GTK_View*>(*it);

		container2->notebook_->remove(**it);

		buffer->setViewContainer(this);
		buffer->createContextMenu();
		notebook_->append_page(*buffer,buffer->getTitle());
		notebook_->set_tab_reorderable(*buffer);
		notebook_->set_tab_detachable(*buffer);

		++it;
	}


	Gtk::Container::remove(*paned_);
	delete paned_;
	paned_=nullptr;


	showTabs(true);


	add(*notebook_);

	isSplit_=false;

	show_all_children();
}

void GTK_ViewContainer::on_context_menu_add_view_empty_view_click() {
	assert( presenter_!=nullptr && "No presenter set for GTK_ViewContainer");

	presenter_->on_context_menu_add_view_click(ViewType::EMPTY_VIEW);
}

void GTK_ViewContainer::on_context_menu_join_click() {
	assert( presenter_!=nullptr && "No presenter set for GTK_ViewContainer");

	presenter_->on_context_menu_join_click();
}

void GTK_ViewContainer::setPresenter(IViewContainerPresenter* presenter) {
	presenter_=presenter;
}

bool GTK_ViewContainer::on_button_press_event(GdkEventButton *ev) {
	assert( presenter_!=nullptr && "No presenter set for GTK_ViewContainer");

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

bool GTK_ViewContainer::isTopLevel() {
	return !isSplit_;
}

void GTK_ViewContainer::split() {
	if(isSplit_)
		return;
	isSplit_=true;

	Gtk::Container::remove(*notebook_);

	GTK_ViewContainer* vc1=new GTK_ViewContainer(get_hadjustment(),get_vadjustment(),notebook_);
	GTK_ViewContainer* vc2=new GTK_ViewContainer(get_hadjustment(),get_vadjustment(),nullptr);

	ViewContainerPresenter* vcp1=new ViewContainerPresenter;
	ViewContainerPresenter* vcp2=new ViewContainerPresenter;

	vcp1->setViewContainer(vc1);
	vcp2->setViewContainer(vc2);

	vcp1->setParent(presenter_);
	vcp2->setParent(presenter_);

	vc1->setPresenter(vcp1);
	vc2->setPresenter(vcp2);

	vc1->set_shadow_type(Gtk::SHADOW_OUT);
	vc2->set_shadow_type(Gtk::SHADOW_OUT);


	paned_->pack1(*vc1,true,false);
	paned_->pack2(*vc2,true,false);


	add(*paned_);

	notebook_=nullptr;


	show_all_children();
}

void GTK_ViewContainer::splitHorizontal() {
	if(isSplit_)
		return;

	paned_=new Gtk::Paned( Gtk::ORIENTATION_HORIZONTAL);
	Gdk::Rectangle rec=get_allocation();
	paned_->set_position(rec.get_width()/2);

	split();
}
void GTK_ViewContainer::splitVertical() {
	if(isSplit_)
		return;

	paned_=new Gtk::Paned( Gtk::ORIENTATION_VERTICAL);
	Gdk::Rectangle rec=get_allocation();
	paned_->set_position(rec.get_height()/2);

	split();
}

void GTK_ViewContainer::addView(ViewType type) {
	switch(type) {
	case ViewType::EMPTY_VIEW: {
		addView(GTK_ViewBuilder::buildEmptyView(this,"Empty View"));
		break;
	}
	default:
		;
	}
}
void GTK_ViewContainer::addView(IView* view) {
	assert(isTopLevel() && "GTK_ViewContainer must be toplevel to add a view");
	assert( notebook_!=nullptr && "No notebook set for GTK_ViewContainer");

	if(notebook_->get_n_pages()>=1)
		showTabs(true);

	GTK_View* buffer=dynamic_cast<GTK_View*>(view);
	notebook_->append_page(*buffer,view->getTitle());
	notebook_->set_tab_reorderable(*buffer);
	notebook_->set_tab_detachable(*buffer);

	show_all_children();
}

void GTK_ViewContainer::showTabs(bool showTabs) {
	notebook_->set_show_tabs(showTabs);
}

Glib::RefPtr<Gtk::Adjustment> GTK_ViewContainer::getHAdjustment() {
	return h_adjustment_;
}

Glib::RefPtr<Gtk::Adjustment> GTK_ViewContainer::getVAdjustment() {
	return v_adjustment_;
}

}//namespace erebus
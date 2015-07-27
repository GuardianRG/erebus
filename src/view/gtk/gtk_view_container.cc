#include <gtk_view_container.h>

#include <gtkmm.h>

#include <assert.h>
#include <iterator>
#include <memory>
#include <typeinfo>

#include <presenter/interfaces/i_view_container_presenter.h>
#include <view/interfaces/i_view_container.h>
#include <presenter/interfaces/i_empty_view_presenter.h>
#include <presenter/interfaces/i_hex_view_presenter.h>

#include <presenter/empty_view_presenter.h>
#include <presenter/hex_view_presenter.h>
#include <presenter/view_container_presenter.h>
#include <view/view_type.h>
#include <gtk_view.h>
#include <view/gui_manager.h>
#include <gtk_logger.h>
#include <gtk_builder_factory.h>
#include <gtk_hex_view.h>
#include <gtk_empty_view.h>
#include <view/view_preferences.h>
#include <glade_files.h>

namespace erebus {

GTK_ViewContainer::GTK_ViewContainer(
    Glib::RefPtr<Gtk::Adjustment> h_adjustment,
    Glib::RefPtr<Gtk::Adjustment> v_adjustment,
    IViewContainer* parent):
	GTK_ViewContainer(h_adjustment,v_adjustment,nullptr,parent) {

}

GTK_ViewContainer::GTK_ViewContainer(
    Glib::RefPtr<Gtk::Adjustment> h_adjustment,
    Glib::RefPtr<Gtk::Adjustment> v_adjustment,
    std::unique_ptr<Gtk::Notebook> notebook,
    IViewContainer* parent):
	Gtk::Viewport(h_adjustment,v_adjustment),
	parent_(parent) {

	//Set up the notebook which contains the views.
	if(notebook==nullptr) {
		notebook_=std::make_unique<Gtk::Notebook>();
		notebook_->set_group_name("notebooks");
		showTabs(ViewPreferences::getInstance().getAlwaysShowTabs());
	} else {
		assert(notebook.get()!=nullptr);
		notebook_=std::move(notebook);
		//Rebind the function pointers of the context menu
		for(auto w:notebook_->get_children()) {
			auto buffer=dynamic_cast<GTK_View*>(w);
			assert(buffer!=0);

			buffer->setParent(this);
			buffer->createContextMenu();

		}

	}

	set_shadow_type(Gtk::SHADOW_NONE);
	notebook_->set_scrollable(true);

	add(*notebook_);

	add_events(Gdk::BUTTON_PRESS_MASK );

#ifndef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
	signal_button_press_event().
	connect(sigc::mem_fun(*this, &GTK_ViewContainer::on_button_press_event), false);
#endif

	//Build popMenu
	popupMenu_=std::make_unique<Gtk::Menu>();
	buildContextMenu(*popupMenu_.get());
	popupMenu_->accelerate(*this);
	popupMenu_->show_all();

	show_all_children();

	clickBuffer_=0;
	timeBuffer_=0;
	isSplit_=false;
	parent_=nullptr;
	paned_=nullptr;
}

GTK_ViewContainer::~GTK_ViewContainer() {

}

bool GTK_ViewContainer::isEmpty(bool recursive) const {
	if(isSplit_) {
		if(recursive) {
			assert(paned_!=nullptr);

			auto ch1=dynamic_cast<GTK_ViewContainer*>(paned_->get_child1());
			auto ch2=dynamic_cast<GTK_ViewContainer*>(paned_->get_child2());

			assert(ch1!=0);
			assert(ch2!=0);

			return ch1->isEmpty(true)&&ch2->isEmpty(true);
		}
		return false;
	}
	assert(notebook_.get()!=nullptr);

	return notebook_->get_n_pages()==0;
}


void GTK_ViewContainer::on_context_menu_split_horizontal_click() {
	assert( presenter_.get()!=nullptr);

	presenter_->on_context_menu_split_horizontal_click();
}

void GTK_ViewContainer::on_context_menu_split_vertical_click() {
	assert( presenter_.get()!=nullptr);

	presenter_->on_context_menu_split_vertical_click();
}

void GTK_ViewContainer::showContextMenu() {
	assert( popupMenu_.get()!=nullptr);

	popupMenu_->popup(clickBuffer_,timeBuffer_);
}

void GTK_ViewContainer::closeView(IView& view) {
	try {
		auto& buffer=dynamic_cast<GTK_View&>(view);
		notebook_->remove_page(buffer);
	} catch(std::bad_cast e) {
		assert(false);
	}
}

void GTK_ViewContainer::removeView(IView& view) {
	try {
		auto& buffer=dynamic_cast<Gtk::Viewport&>(view);
		notebook_->remove(buffer);
	} catch(std::bad_cast e) {
		assert(false);
	}
	show_all_children();
}

void GTK_ViewContainer::setParent(IViewContainer* parent) {
	parent_=parent;
}

void GTK_ViewContainer::buildContextMenu(Gtk::Menu& menu) {
	//Separator Item
	auto sep=Gtk::manage(new Gtk::SeparatorMenuItem);

	//Control submenu
	auto control=Gtk::manage(new Gtk::MenuItem{"Control"});
	auto control_menu=Gtk::manage(new Gtk::Menu);
	control->set_submenu(*control_menu);

	//Join item
	auto join=Gtk::manage(new Gtk::MenuItem{"Join"});
	join->set_sensitive(false);
	if(parent_!=nullptr) {
		if(parent_->isSplit()) {
			join->set_sensitive(true);

		}
	}
	join->signal_activate().
	connect(
	    sigc::mem_fun(*this,
	                  &GTK_ViewContainer::on_context_menu_join_click)
	);

	//Split submenu
	auto split=Gtk::manage(new Gtk::MenuItem{"Split"});
	auto add_view = Gtk::manage(new Gtk::MenuItem{"Add View"});

	auto split_menu=Gtk::manage(new Gtk::Menu);

	auto split_h = Gtk::manage(new Gtk::MenuItem{"Horizontal"});
	auto split_v = Gtk::manage(new Gtk::MenuItem{"Vertical"});

	split_h->signal_activate().
	connect(sigc::mem_fun(*this,
	                      &GTK_ViewContainer::on_context_menu_split_horizontal_click) );

	split_v->signal_activate().
	connect(sigc::mem_fun(*this,
	                      &GTK_ViewContainer::on_context_menu_split_vertical_click) );

	split_menu->append(*split_h);
	split_menu->append(*split_v);

	split->set_submenu(*split_menu);

	//View submenu
	auto view_menu=Gtk::manage(new Gtk::Menu);

	auto empty_view = Gtk::manage(new Gtk::MenuItem{"Empty View"});
	empty_view->signal_activate().
	connect(sigc::mem_fun(*this,
	                      &GTK_ViewContainer::on_context_menu_add_view_empty_view_click) );
	view_menu->append(*empty_view);

	auto hex_view = Gtk::manage(new Gtk::MenuItem{"Hex View"});
	hex_view->signal_activate().
	connect(sigc::mem_fun(*this,
	                      &GTK_ViewContainer::on_context_menu_add_view_hex_view_click) );
	view_menu->append(*hex_view);

	add_view->set_submenu(*view_menu);

	//Add everything to the menu
	menu.append(*sep);
	control_menu->append(*join);
	control_menu->append(*split);
	control_menu->append(*add_view);
	menu.append(*control);
}

void GTK_ViewContainer::joinContainer() {
	if(!isSplit_)
		return;
	isSplit_=false;

	BOOST_LOG_SEV(gtk_l::get(),normal)<<LOCATION<<"Joining view container '"<<this<<"'";

	assert(paned_!=nullptr);

	//Get both containers
	auto container1=dynamic_cast<GTK_ViewContainer*>(paned_->get_child1());
	auto container2=dynamic_cast<GTK_ViewContainer*>(paned_->get_child2());

	assert(container1!=0);
	assert(container2!=0);

	//If one of the containers is splitted join them too
	if(!container1->isTopLevel()) {
		container1->joinContainer();
	}
	if(!container2->isTopLevel()) {
		container2->joinContainer();
	}

	assert(container1->notebook_.get()!=nullptr);
	assert(container2->notebook_.get()!=nullptr);

	//Create the new notebook
	notebook_=std::make_unique<Gtk::Notebook>();
	notebook_->set_group_name("notebooks");

	auto children=container1->notebook_->get_children();

	//Put the views of container 1 into the notebook
	for(auto it:children) {
		auto buffer=dynamic_cast<GTK_View*>(it);
		assert(buffer!=0);

		container1->notebook_->remove(*it);

		//Rebind pointers of the contextmenu
		buffer->setParent(this);
		buffer->createContextMenu();

		notebook_->append_page(*buffer,buffer->getTitle());
		notebook_->set_tab_reorderable(*buffer);
		notebook_->set_tab_detachable(*buffer);
	}


	children=container2->notebook_->get_children();
	//Put the views of container 2 into the notebook
	for(auto it:children) {
		auto buffer=dynamic_cast<GTK_View*>(it);
		assert(buffer!=0);

		container2->notebook_->remove(*it);

		//Rebind pointers of the context menu
		buffer->setParent(this);
		buffer->createContextMenu();

		notebook_->append_page(*buffer,buffer->getTitle());
		notebook_->set_tab_reorderable(*buffer);
		notebook_->set_tab_detachable(*buffer);
	}

	Gtk::Container::remove(*paned_);
	paned_=nullptr;

	showTabs(ViewPreferences::getInstance().getAlwaysShowTabs());

	add(*notebook_);

	show_all_children();
}

void GTK_ViewContainer::on_context_menu_add_view_empty_view_click() {
	assert( presenter_.get()!=nullptr);

	presenter_->on_context_menu_add_view_click(ViewType::EMPTY_VIEW);
}

void GTK_ViewContainer::on_context_menu_add_view_hex_view_click() {
	assert( presenter_.get()!=nullptr);

	presenter_->on_context_menu_add_view_click(ViewType::HEX_VIEW);
}

void GTK_ViewContainer::on_context_menu_join_click() {
	assert( presenter_.get()!=nullptr);

	presenter_->on_context_menu_join_click();
}

void GTK_ViewContainer::setPresenter(std::unique_ptr<IViewContainerPresenter> presenter) {
	assert(presenter.get()!=nullptr);

	presenter_=std::move(presenter);
}

IViewContainer* GTK_ViewContainer::getParent() const {
	return parent_;
}

bool GTK_ViewContainer::on_button_press_event(GdkEventButton *ev) {
	assert( presenter_.get()!=nullptr);

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

bool GTK_ViewContainer::isTopLevel() const {
	return !isSplit_;
}

bool GTK_ViewContainer::isSplit() const {
	return isSplit_;
}

void GTK_ViewContainer::split() {
	if(isSplit_)
		return;
	isSplit_=true;

	assert(notebook_.get()!=nullptr);

	Gtk::Container::remove(*notebook_);

	//Create both containers for the paned
	auto vc1=Gtk::manage(new GTK_ViewContainer(
	                         get_hadjustment(),
	                         get_vadjustment(),
	                         std::move(notebook_),this)
	                    );

	auto vc2=Gtk::manage(new GTK_ViewContainer(get_hadjustment(),get_vadjustment(),this));

	//Create the presenters of the container
	auto vcp1=std::unique_ptr<IViewContainerPresenter>(
	              std::make_unique<ViewContainerPresenter>()
	          );

	auto vcp2=std::unique_ptr<IViewContainerPresenter>(
	              std::make_unique<ViewContainerPresenter>()
	          );

	vcp1->setViewContainer(vc1);
	vcp2->setViewContainer(vc2);

	vc1->setPresenter(std::move(vcp1));
	vc2->setPresenter(std::move(vcp2));

	vc1->setParent(this);
	vc2->setParent(this);

	paned_->pack1(*vc1,true,false);
	paned_->pack2(*vc2,true,false);

	add(*paned_);

	show_all_children();
}

void GTK_ViewContainer::popOutView(IView& view) {
	if(!isTopLevel())
		return;
	removeView(view);
	GUIManager::getInstance().moveViewToNewWindow(view);
}

void GTK_ViewContainer::splitHorizontal() {
	if(isSplit_)
		return;

	BOOST_LOG_SEV(gtk_l::get(),normal)
			<<LOCATION<<"Splitting view container '"<<this<<"' horizontally";

	//Create horizontal paned
	paned_=Gtk::manage(new Gtk::Paned( Gtk::ORIENTATION_HORIZONTAL));
	auto rec=get_allocation();
	paned_->set_position(rec.get_width()/2);

	split();
}
void GTK_ViewContainer::splitVertical() {
	if(isSplit_)
		return;

	BOOST_LOG_SEV(gtk_l::get(),normal)
			<<LOCATION<<"Splitting view container '"<<this<<"' vertically";

	//Create vertical paned
	paned_=Gtk::manage(new Gtk::Paned( Gtk::ORIENTATION_VERTICAL));
	auto rec=get_allocation();
	paned_->set_position(rec.get_height()/2);

	split();
}

void GTK_ViewContainer::addView(ViewType type) {
	//I really would love to outsource the creation of the views into
	//a factory class but unfortunatly his is not possible since the buildrt
	//has to exist until ownership of the view is transferred to this container.
	//This would lead to unnecessary moving of objects so it will stay this way
	//until i found a suitible solution.

	switch(type) {
	case ViewType::EMPTY_VIEW: {
		auto title=std::string{"Empty View"};

		auto presenter=std::unique_ptr<IEmptyViewPresenter>(
		                   std::make_unique<EmptyViewPresenter>()
		               );

		auto builder=GTK_BuilderFactory::getBuilder(Views::EMPTY_VIEW);
		GTK_EmptyView* view;
		builder->get_widget_derived("empty_view",view);
		presenter->setView(view);
		view->setPresenter(std::move(presenter));
		view->setTitle(title);
		view->setParent(this);
		view->createContextMenu();
		addView(*view);
		break;
	}
	case ViewType::HEX_VIEW: {
		auto title=std::string{"Hex View"};

		auto presenter=std::unique_ptr<IHexViewPresenter>(
		                   std::make_unique<HexViewPresenter>()
		               );

		auto builder=GTK_BuilderFactory::getBuilder(Views::HEX_VIEW);
		GTK_HexView* view;
		builder->get_widget_derived("hex_view",view);
		presenter->setView(view);
		view->setPresenter(std::move(presenter));
		view->setTitle(title);
		view->setParent(this);
		view->createContextMenu();
		addView(*view);
		break;
	}
	default:
		;
	}
}
void GTK_ViewContainer::addView(IView& view) {
	if(!isTopLevel()) {
		assert(paned_!=nullptr);

		auto ch1=dynamic_cast<GTK_ViewContainer*>(paned_->get_child1());
		assert(ch1!=0);

		ch1->addView(view);
	} else {
		assert(notebook_.get()!=nullptr);

		if(notebook_->get_n_pages()>=1)
			showTabs(true);

		try {
			auto& buffer=dynamic_cast<GTK_View&>(view);
			notebook_->append_page(buffer,view.getTitle());
			notebook_->set_tab_reorderable(buffer);
			notebook_->set_tab_detachable(buffer);
		} catch(std::bad_cast e) {
			assert(false);
		}

	}
	show_all_children();
}

void GTK_ViewContainer::showTabs(bool showTabs) {
	if(notebook_.get()!=nullptr) {
		notebook_->set_show_tabs(showTabs);
	} else {
		assert(paned_!=nullptr);
		auto container1=dynamic_cast<GTK_ViewContainer*>(paned_->get_child1());
		auto container2=dynamic_cast<GTK_ViewContainer*>(paned_->get_child2());
		assert(container1!=0);
		assert(container2!=0);
		container1->showTabs(showTabs);
		container2->showTabs(showTabs);
	}
}

Glib::RefPtr<Gtk::Adjustment> GTK_ViewContainer::getHAdjustment() {
	return get_hadjustment();
}

Glib::RefPtr<Gtk::Adjustment> GTK_ViewContainer::getVAdjustment() {
	return get_vadjustment();
}

}//namespace erebus

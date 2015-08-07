#include <gtk_view_container.h>

#include <gtkmm/menu.h>
#include <glibmm/refptr.h>
#include <gtkmm/adjustment.h>
#include <gtkmm/menuitem.h>
#include <gtkmm/separatormenuitem.h>
#include <gdk/gdk.h>
#include <gtkmm/notebook.h>
#include <glibmm/exception.h>
#include <gtkmm/paned.h>
#include <gtkmm/viewport.h>

#include <memory>

#include <presenter/interfaces/i_view_container_presenter.h>
#include <view/interfaces/i_gui_manager.h>
#include <view/interfaces/i_gui_object.h>
#include <view/interfaces/i_view.h>

#include <gtk_logger.h>
#include <gtk_view_container_factory.h>
#include <view/view_type.h>
#include <gtk_view.h>
#include <gtk_view_factory.h>
#include <gtk_empty_view.h>

INIT_LOCATION;

namespace erebus {

const std::string GTK_ViewContainer::CLASSNAME="GTK_ViewContainer";

GTK_ViewContainer::GTK_ViewContainer(
    Glib::RefPtr<Gtk::Adjustment> h_adjustment,
    Glib::RefPtr<Gtk::Adjustment> v_adjustment,
    std::unique_ptr<Gtk::Notebook> notebook,IGUIManager& manager):
	Gtk::Viewport(h_adjustment,v_adjustment),timeBuffer_(0),clickBuffer_(0),isSplitted_(false) {

	LOG_CONSTRUCTOR;

	setGUIManager(manager);

	set_shadow_type(Gtk::SHADOW_NONE);

	add_events(Gdk::BUTTON_PRESS_MASK );

#ifndef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
	signal_button_press_event().connect(sigc::mem_fun(*this, &GTK_ViewContainer::on_button_press_event),
	                                    false);
#endif
	if(notebook.get()==nullptr) {
		notebook_=std::make_unique<Gtk::Notebook>();
	} else {
		notebook_=std::move(notebook);
	}
	notebook_->set_group_name("notebooks");
	notebook_->set_scrollable(true);
	add(*notebook_);

	buildContextMenu();
	updateContextMenu();

	show_all_children();
}

GTK_ViewContainer::~GTK_ViewContainer() {
	LOG_DESTRUCTOR;
}

void GTK_ViewContainer::on_context_menu_split_horizontal_click() {
	LOG_ASSERT(gtk_l::get(), presenter_.get()!=nullptr);

	presenter_->on_context_menu_split_horizontal_click();
}

void GTK_ViewContainer::on_context_menu_split_vertical_click() {
	LOG_ASSERT(gtk_l::get(), presenter_.get()!=nullptr);

	presenter_->on_context_menu_split_vertical_click();
}

void GTK_ViewContainer::showContextMenu() {
	LOG_ASSERT(gtk_l::get(), popupMenu_.get()!=nullptr);
	static bool init=false;
	if(!init) {
		auto parent=guiManager_->getParentOf(getID());
		if(parent!=nullptr) {
			if(parent->classname()!=GTK_ViewContainer::CLASSNAME)
				joinItem_->set_sensitive(false);
		} else {
			BOOST_LOG_SEV(gtk_l::get(),warning)
			        <<LOCATION<<"There is somewehere a bug in the getParentOf() method";
		}
		init=true;
	}
	updateContextMenu();
	popupMenu_->popup(clickBuffer_,timeBuffer_);
}

void GTK_ViewContainer::updateContextMenu() {
	if(isSplitted())
		LOG_ASSERT(gtk_l::get(),false);
	LOG_ASSERT(gtk_l::get(),notebook_.get()!=nullptr);

	static int currentPage=-2;
	if(notebook_->get_n_pages()>=1) {


		if(currentPage!=notebook_->get_current_page()) {
			buildContextMenu();
			currentPage=notebook_->get_current_page();
			auto child=dynamic_cast<GTK_View*>(notebook_->get_nth_page(currentPage));

			if(child!=0) {
				auto child_menu=std::move(child->createContextMenu());
				auto menu_entries=child_menu->get_children();
				for(std::size_t i=0; i<menu_entries.size(); i++) {
					auto item=dynamic_cast<Gtk::MenuItem*>(menu_entries.at(i));
					if(item!=0) {
						child_menu->remove(*item);
						item->show();
						popupMenu_->insert(*Gtk::manage(item),i);
					} else {
						LOG_GTK(error)<<"Cast failed.";
					}
				}
			} else {
				LOG_GTK(error)<<"Cast failed.";
			}

			viewItem_->show();
			separator_->show();
		}
	} else {
		currentPage=-2;
		buildContextMenu();
		viewItem_->hide();
		separator_->hide();
	}
}

void GTK_ViewContainer::addView(IView& view) {
	try {
		auto& view_c=dynamic_cast<GTK_View&>(view);
		addViewPr(view_c);
	} catch(const std::bad_cast& e) {
		LOG_GTK(error)<<"Cast failed.";
	}
}

void GTK_ViewContainer::buildContextMenu() {
	LOG_ASSERT(gtk_l::get(),guiManager_!=nullptr);

	popupMenu_=std::make_unique<Gtk::Menu>();

	//Separator Item
	auto sep=Gtk::manage(new Gtk::SeparatorMenuItem);
	auto sep1=Gtk::manage(new Gtk::SeparatorMenuItem);
	auto sep2=Gtk::manage(new Gtk::SeparatorMenuItem);
	auto sep3=Gtk::manage(new Gtk::SeparatorMenuItem);
	separator_=std::make_unique<Gtk::SeparatorMenuItem>();

	viewItem_=std::make_unique<Gtk::MenuItem>("View");
	auto view_c_menu=Gtk::manage(new Gtk::Menu);
	viewItem_->set_submenu(*view_c_menu);


	auto popout_item=Gtk::manage(new Gtk::MenuItem("Pop out"));
	popout_item->signal_activate().
	connect(
	    sigc::mem_fun(*this,
	                  &GTK_ViewContainer::on_context_menu_pop_out_click)
	);

	auto close_item=Gtk::manage(new Gtk::MenuItem("Close"));
	close_item->signal_activate().
	connect(
	    sigc::mem_fun(*this,
	                  &GTK_ViewContainer::on_context_menu_close_click)
	);

	//Control submenu
	auto control=Gtk::manage(new Gtk::MenuItem{"Control"});
	auto control_menu=Gtk::manage(new Gtk::Menu);
	control->set_submenu(*control_menu);

	//Join item
	joinItem_=std::make_unique<Gtk::MenuItem>("Join");
	joinItem_->signal_activate().
	connect(
	    sigc::mem_fun(*this,
	                  &GTK_ViewContainer::on_context_menu_join_click)
	);

	auto split_h = Gtk::manage(new Gtk::MenuItem{"Split Horizontal"});
	auto split_v = Gtk::manage(new Gtk::MenuItem{"Split Vertical"});

	split_h->signal_activate().
	connect(sigc::mem_fun(*this,
	                      &GTK_ViewContainer::on_context_menu_split_horizontal_click) );

	split_v->signal_activate().
	connect(sigc::mem_fun(*this,
	                      &GTK_ViewContainer::on_context_menu_split_vertical_click) );

	auto add_view = Gtk::manage(new Gtk::MenuItem{"Add View"});
	auto view_menu=Gtk::manage(new Gtk::Menu);

	auto empty_view = Gtk::manage(new Gtk::MenuItem{"Empty View"});
	view_menu->append(*empty_view);
	empty_view->signal_activate().
	connect(sigc::mem_fun(*this,
	                      &GTK_ViewContainer::on_context_menu_add_empty_view_click) );
	add_view->set_submenu(*view_menu);

	popupMenu_->append(*separator_);
	view_c_menu->append(*popout_item);
	view_c_menu->append(*sep3);
	view_c_menu->append(*close_item);
	popupMenu_->append(*viewItem_);
	popupMenu_->append(*sep);
	control_menu->append(*joinItem_);
	control_menu->append(*sep1);
	control_menu->append(*split_h);
	control_menu->append(*split_v);
	control_menu->append(*sep2);
	control_menu->append(*add_view);
	popupMenu_->append(*control);

	popupMenu_->accelerate(*this);
	popupMenu_->show_all();
}

void GTK_ViewContainer::on_context_menu_close_click() {
	LOG_ASSERT(gtk_l::get(),presenter_.get()!=nullptr);

	presenter_->on_context_menu_close_click();
}

void GTK_ViewContainer::closeActiveView() {
	LOG_ASSERT(gtk_l::get(),!isSplitted());
	LOG_ASSERT(gtk_l::get(),notebook_.get()!=nullptr);
	LOG_ASSERT(gtk_l::get(),notebook_->get_n_pages()>=1);

	auto activeView=notebook_->get_nth_page(notebook_->get_current_page());
	auto activeViewC=dynamic_cast<IView*>(activeView);
	if(activeViewC==0) {
		LOG_GTK(error)<<"Cast failed.";
		return;
	}
	closeView(*activeViewC);
}

void GTK_ViewContainer::join() {
	if(!isSplitted())
		return;
	isSplitted_=false;

	LOG_GTK(normal)<<"Joining view container '"<<getID()<<"'";
	try {
		LOG_ASSERT(gtk_l::get(),paned_.get()!=nullptr);
		LOG_ASSERT(gtk_l::get(),child1_.get()!=nullptr);
		LOG_ASSERT(gtk_l::get(),child2_.get()!=nullptr);

		if(!child1_->isTopLevel()) {
			child1_->join();
		}
		if(!child2_->isTopLevel()) {
			child2_->join();
		}

		notebook_=std::make_unique<Gtk::Notebook>();
		notebook_->set_group_name("notebooks");

		LOG_ASSERT(gtk_l::get(),child1_->notebook_.get()!=nullptr);

		for(auto it:child1_->notebook_->get_children()) {
			auto buffer=dynamic_cast<GTK_View*>(it);

			if(buffer==0) {
				BOOST_LOG_SEV(gtk_l::get(),error)<<LOCATION<<"Cast failed.";
				continue;
			}

			child1_->notebook_->remove(*it);

			addView(*buffer);
		}

		LOG_ASSERT(gtk_l::get(),child2_->notebook_.get()!=nullptr);

		for(auto it:child2_->notebook_->get_children()) {
			auto buffer=dynamic_cast<GTK_View*>(it);

			if(buffer==0) {
				BOOST_LOG_SEV(gtk_l::get(),error)<<LOCATION<<"Cast failed.";
				continue;
			}

			child2_->notebook_->remove(*it);

			addView(*buffer);
		}

		paned_->remove(*(child1_.get()));
		paned_->remove(*(child2_.get()));
		Gtk::Container::remove(*(paned_.get()));
		paned_=std::unique_ptr<Gtk::Paned>(nullptr);
		child1_=std::unique_ptr<GTK_ViewContainer>(nullptr);
		child2_=std::unique_ptr<GTK_ViewContainer>(nullptr);

		show_all_children();

		add(*notebook_);
	} catch(const std::exception& e) {
		isSplitted_=true;
		BOOST_LOG_SEV(gtk_l::get(),error)<<"Joining the view container '"<<getID()<<"' failed. ("<<e.what()
		                                 <<")";
		guiManager_->showMessageDialog(getID(),"Joining the container failes!",e.what(),ErrorLevel::ERROR);
	} catch(const Glib::Exception& e) {
		isSplitted_=true;
		BOOST_LOG_SEV(gtk_l::get(),error)<<"Joining the view container '"<<getID()<<"' failed. ("<<e.what()
		                                 <<")";
		guiManager_->showMessageDialog(getID(),"Joining the container failes!",e.what(),ErrorLevel::ERROR);
	}
	show_all_children();
}

void GTK_ViewContainer::on_context_menu_add_empty_view_click() {
	LOG_ASSERT(gtk_l::get(), presenter_.get()!=nullptr);

	presenter_->on_context_menu_add_view_click(ViewType::EMPTY_VIEW);
}

void GTK_ViewContainer::on_context_menu_join_click() {
	LOG_ASSERT(gtk_l::get(), presenter_.get()!=nullptr);

	presenter_->on_context_menu_join_click();
}

void GTK_ViewContainer::setPresenter(std::unique_ptr<IViewContainerPresenter> presenter) {
	LOG_ASSERT(gtk_l::get(),presenter.get()!=nullptr);

	presenter_=std::move(presenter);
}

void GTK_ViewContainer::on_context_menu_pop_out_click() {
	LOG_ASSERT_GTK(presenter_.get()!=nullptr);

	presenter_->on_context_menu_pop_out_click();
}

IView* GTK_ViewContainer::getActiveView() {
	LOG_ASSERT_GTK(notebook_.get()!=nullptr);

	if(notebook_->get_n_pages()==0)
		return nullptr;

	auto view=dynamic_cast<IView*>(notebook_->get_nth_page(notebook_->get_current_page()));

	if(view==0) {
		LOG_GTK(error)<<"Cast failed.";
		return nullptr;
	}
	return view;
}

void GTK_ViewContainer::removeView(IView& view) {
	try {
		auto& buffer=dynamic_cast<Gtk::Viewport&>(view);
		notebook_->remove(buffer);
	} catch(std::bad_cast e) {
		LOG_GTK(error)<<"Cast failed.";
	}
	show_all_children();
}

bool GTK_ViewContainer::on_button_press_event(GdkEventButton *ev) {
	LOG_ASSERT(gtk_l::get(), presenter_.get()!=nullptr);

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

bool GTK_ViewContainer::containsWidget(std::size_t id) {
	if(isSplitted()) {
		LOG_ASSERT(gtk_l::get(),child1_.get()!=nullptr);
		LOG_ASSERT(gtk_l::get(),child2_.get()!=nullptr);

		if(child1_->getID()==id||child2_->getID()==id)
			return true;

		return child1_->containsWidget(id)||child2_->containsWidget(id);
	} else {
		LOG_ASSERT(gtk_l::get(),notebook_.get()!=nullptr);

		for(auto it:notebook_->get_children()) {
			auto buffer=dynamic_cast<IGUIObject*>(it);
			if(buffer==0) {
				BOOST_LOG_SEV(gtk_l::get(),error)<<LOCATION<<"Cast failed.";
				continue;
			} else if(buffer->getID()==id) {
				return true;
			}
		}
	}
	return false;
}

void GTK_ViewContainer::closeView(IView& view) {
	try {
		auto& buffer=dynamic_cast<GTK_View&>(view);
		notebook_->remove_page(buffer);
	} catch(std::bad_cast e) {
		LOG_GTK(error)<<"Cast failed.";
	}
}

bool GTK_ViewContainer::isTopLevel() const {
	return !isSplitted();
}

bool GTK_ViewContainer::isSplitted() const {
	return isSplitted_;
}

void GTK_ViewContainer::split() {
	if(isSplitted()) {
		LOG_ASSERT(gtk_l::get(),false);
		return;
	}

	isSplitted_=true;
	try {
		LOG_ASSERT(gtk_l::get(),paned_.get()!=nullptr);
		LOG_ASSERT(gtk_l::get(),guiManager_!=nullptr);
		LOG_ASSERT(gtk_l::get(),notebook_.get()!=nullptr);

		Gtk::Container::remove(*notebook_);

		child1_=GTK_ViewContainerFactory::createViewContainer(*guiManager_,get_hadjustment(),
		        get_vadjustment(),std::move(notebook_));
		child2_=GTK_ViewContainerFactory::createViewContainer(*guiManager_,get_hadjustment(),
		        get_vadjustment());

		paned_->pack1(*(child1_.get()),true,false);
		paned_->pack2(*(child2_.get()),true,false);

		add(*paned_);

	} catch(const std::exception& e) {
		isSplitted_=false;
		BOOST_LOG_SEV(gtk_l::get(),error)<<"Splitting the view container '"<<getID()
		                                 <<"' failed. ("<<e.what()<<")";
		guiManager_->showMessageDialog(getID(),"Splitting the container failes!",e.what(),
		                               ErrorLevel::ERROR);
	} catch(const Glib::Exception& e) {
		isSplitted_=false;
		BOOST_LOG_SEV(gtk_l::get(),error)<<"Splitting the view container '"<<getID()
		                                 <<"' failed. ("<<e.what()<<")";
		guiManager_->showMessageDialog(getID(),"Splitting the container failes!",e.what(),
		                               ErrorLevel::ERROR);
	}
	show_all_children();
}

void GTK_ViewContainer::splitHorizontal() {
	if(isSplitted())
		return;

	BOOST_LOG_SEV(gtk_l::get(),normal)
	        <<LOCATION<<"Splitting "<<classname()<<" '"<<getID()<<"' horizontally";

	paned_=std::make_unique<Gtk::Paned>( Gtk::ORIENTATION_HORIZONTAL);
	auto rec=get_allocation();
	paned_->set_position(rec.get_width()/2);

	split();
}
void GTK_ViewContainer::splitVertical() {
	if(isSplitted())
		return;

	BOOST_LOG_SEV(gtk_l::get(),normal)
	        <<LOCATION<<"Splitting "<<classname()<<" '"<<getID()<<"' vertically";

	paned_=std::make_unique<Gtk::Paned>( Gtk::ORIENTATION_VERTICAL);
	auto rec=get_allocation();
	paned_->set_position(rec.get_height()/2);

	split();
}


void GTK_ViewContainer::addView(ViewType type) {

	switch(type) {
	case ViewType::EMPTY_VIEW: {
		auto title=std::string{"Empty View"};

		auto view=GTK_ViewFactory::createEmptyView(*guiManager_);
		view->setTitle(title);
		addViewPr(*view);
		break;
	}

	default:
		;
	}
}

void GTK_ViewContainer::addViewPr(GTK_View& view) {
	if(!isTopLevel()) {
		LOG_ASSERT(gtk_l::get(),false);
	}
	LOG_ASSERT(gtk_l::get(),notebook_.get()!=nullptr);

	if(notebook_->get_n_pages()>=1)
		notebook_->set_show_tabs(true);

	notebook_->append_page(view,view.getTitle());
	notebook_->set_tab_reorderable(view);
	notebook_->set_tab_detachable(view);

	show_all_children();
}

IGUIObject* GTK_ViewContainer::getParentOf(std::size_t id) {
	if(!containsWidget(id))
		return nullptr;

	if(isSplitted()) {
		LOG_ASSERT(gtk_l::get(),child1_.get()!=nullptr);
		LOG_ASSERT(gtk_l::get(),child2_.get()!=nullptr);

		auto ch1=child1_->getParentOf(id);
		auto ch2=child2_->getParentOf(id);

		if(ch1==nullptr&&ch2==nullptr) {
			return this;
		}

		return ch1==nullptr?ch2:ch1;
	} else {
		if(containsWidget(id)) {
			return this;
		}
	}

	return nullptr;
}
std::size_t GTK_ViewContainer::getID() {
	return reinterpret_cast<std::size_t>(this);
}

std::string GTK_ViewContainer::classname() {
	return CLASSNAME;
}

void GTK_ViewContainer::setGUIManager(IGUIManager& manager) {
	guiManager_=&manager;
}

IGUIManager& GTK_ViewContainer::getGUIManager() {
	LOG_ASSERT(gtk_l::get(),guiManager_!=nullptr);
	return *guiManager_;
}

}//namespace erebus

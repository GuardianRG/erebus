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

#include <gtk_logger.h>
#include <gtk_view_container_factory.h>

INIT_LOCATION;

namespace erebus {

const std::string GTK_ViewContainer::CLASSNAME="GTK_ViewContainer";

GTK_ViewContainer::GTK_ViewContainer(
    Glib::RefPtr<Gtk::Adjustment> h_adjustment,
    Glib::RefPtr<Gtk::Adjustment> v_adjustment,
    std::unique_ptr<Gtk::Notebook> notebook,IGUIManager& manager):
	Gtk::Viewport(h_adjustment,v_adjustment),timeBuffer_(0),clickBuffer_(0),isSplitted_(false) {

	BOOST_LOG_SEV(gtk_l::get(),normal)<<LOCATION<<"Constructing "<<classname()<<" '"<<getID()<<"'";

	setGUIManager(manager);

	set_shadow_type(Gtk::SHADOW_NONE);

	add_events(Gdk::BUTTON_PRESS_MASK );

#ifndef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
	signal_button_press_event().connect(sigc::mem_fun(*this, &GTK_ViewContainer::on_button_press_event),
	                                    false);
#endif

	buildContextMenu();

	/*//Set up the notebook which contains the views.
	if(notebook==nullptr) {
		notebook_=std::make_unique<Gtk::Notebook>();
		notebook_->set_group_name("notebooks");
		//showTabs(ViewPreferences::getInstance().getAlwaysShowTabs());
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

	notebook_->set_scrollable(true);

	add(*notebook_);



	//Build popMenu
	popupMenu_=std::make_unique<Gtk::Menu>();
	buildContextMenu(*popupMenu_.get());
	popupMenu_->accelerate(*this);
	popupMenu_->show_all();




	isSplit_=false;
	paned_=nullptr;*/


	show_all_children();
}

GTK_ViewContainer::~GTK_ViewContainer() {
	BOOST_LOG_SEV(gtk_l::get(),normal)<<LOCATION<<"Destructing "<<classname()<<" '"<<getID()<<"'";
}

/*bool GTK_ViewContainer::isEmpty(bool recursive) const {
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
*/

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
	popupMenu_->popup(clickBuffer_,timeBuffer_);
}
/*
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
*/
void GTK_ViewContainer::buildContextMenu() {
	LOG_ASSERT(gtk_l::get(),popupMenu_.get()==nullptr);
	LOG_ASSERT(gtk_l::get(),guiManager_!=nullptr);

	popupMenu_=std::make_unique<Gtk::Menu>();

	//Separator Item
	auto sep=Gtk::manage(new Gtk::SeparatorMenuItem);
	auto sep1=Gtk::manage(new Gtk::SeparatorMenuItem);
	auto sep2=Gtk::manage(new Gtk::SeparatorMenuItem);

	//Control submenu
	auto control=Gtk::manage(new Gtk::MenuItem{"Control"});
	auto control_menu=Gtk::manage(new Gtk::Menu);
	control->set_submenu(*control_menu);

	//Join item
	joinItem_=std::make_unique<Gtk::MenuItem>("Join");
	/*auto parent=guiManager_->getParentOf(getID());
	if(parent!=nullptr) {
		BOOST_LOG_SEV(gtk_l::get(),normal)<<parent->classname();
	if(!(parent->classname()==GTK_ViewContainer::CLASSNAME)) {
		joinItem_->set_sensitive(false);
	}
	}else {
		BOOST_LOG_SEV(gtk_l::get(),warning)<<LOCATION<<"There is a bug in the getParentOf() method";
	}*/
	joinItem_->signal_activate().
	connect(
	    sigc::mem_fun(*this,
	                  &GTK_ViewContainer::on_context_menu_join_click)
	);

	//Split submenu
	//auto add_view = Gtk::manage(new Gtk::MenuItem{"Add View"});

	auto split_h = Gtk::manage(new Gtk::MenuItem{"Split Horizontal"});
	auto split_v = Gtk::manage(new Gtk::MenuItem{"Split Vertical"});

	split_h->signal_activate().
	connect(sigc::mem_fun(*this,
	                      &GTK_ViewContainer::on_context_menu_split_horizontal_click) );

	split_v->signal_activate().
	connect(sigc::mem_fun(*this,
	                      &GTK_ViewContainer::on_context_menu_split_vertical_click) );

	//View submenu
	/*auto view_menu=Gtk::manage(new Gtk::Menu);

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

	add_view->set_submenu(*view_menu);*/

	//Add everything to the menu
	popupMenu_->append(*sep);
	control_menu->append(*joinItem_);
	control_menu->append(*sep1);
	control_menu->append(*split_h);
	control_menu->append(*split_v);
	control_menu->append(*sep2);
	//control_menu->append(*add_view);
	popupMenu_->append(*control);

	popupMenu_->accelerate(*this);
	popupMenu_->show_all();
}

void GTK_ViewContainer::join() {
	if(!isSplitted())
		return;
	isSplitted_=false;

	BOOST_LOG_SEV(gtk_l::get(),
	              normal)<<LOCATION<<"Joining view container '"<<getID()<<"'";
	try {
		LOG_ASSERT(gtk_l::get(),paned_.get()!=nullptr);
		LOG_ASSERT(gtk_l::get(),child1_.get()!=nullptr);
		LOG_ASSERT(gtk_l::get(),child2_.get()!=nullptr);

		//If one of the containers is splitted join them too
		if(!child1_->isTopLevel()) {
			child1_->join();
		}
		if(!child2_->isTopLevel()) {
			child2_->join();
		}

		//assert(container1->notebook_.get()!=nullptr);
		//assert(container2->notebook_.get()!=nullptr);

		//Create the new notebook
		//notebook_=std::make_unique<Gtk::Notebook>();
		//notebook_->set_group_name("notebooks");

		/*auto children=container1->notebook_->get_children();

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
		}*/

		paned_->remove(*(child1_.get()));
		paned_->remove(*(child2_.get()));
		Gtk::Container::remove(*(paned_.get()));
		paned_=std::unique_ptr<Gtk::Paned>(nullptr);
		child1_=std::unique_ptr<GTK_ViewContainer>(nullptr);
		child2_=std::unique_ptr<GTK_ViewContainer>(nullptr);

		//showTabs(ViewPreferences::getInstance().getAlwaysShowTabs());

		//add(*notebook_);
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
/*
void GTK_ViewContainer::on_context_menu_add_view_empty_view_click() {
	assert( presenter_.get()!=nullptr);

	presenter_->on_context_menu_add_view_click(ViewType::EMPTY_VIEW);
}

void GTK_ViewContainer::on_context_menu_add_view_hex_view_click() {
	assert( presenter_.get()!=nullptr);

	presenter_->on_context_menu_add_view_click(ViewType::HEX_VIEW);
}
*/
void GTK_ViewContainer::on_context_menu_join_click() {
	LOG_ASSERT(gtk_l::get(), presenter_.get()!=nullptr);

	presenter_->on_context_menu_join_click();
}

void GTK_ViewContainer::setPresenter(std::unique_ptr<IViewContainerPresenter> presenter) {
	LOG_ASSERT(gtk_l::get(),presenter.get()!=nullptr);

	presenter_=std::move(presenter);
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
		//TODO::check for views
	}
	return false;
}

bool GTK_ViewContainer::isTopLevel() const {
	return !isSplitted();
}

bool GTK_ViewContainer::isSplitted() const {
	return isSplitted_;
}

void GTK_ViewContainer::split() {
	if(isSplitted())
		return;
	isSplitted_=true;
	try {
		LOG_ASSERT(gtk_l::get(),paned_.get()!=nullptr);
		LOG_ASSERT(gtk_l::get(),guiManager_!=nullptr);
		//assert(notebook_.get()!=nullptr);

		//Gtk::Container::remove(*notebook_);

		//Create both containers for the paned
		child1_=GTK_ViewContainerFactory::createViewContainer(*guiManager_,get_hadjustment(),
		        get_vadjustment());
		child2_=GTK_ViewContainerFactory::createViewContainer(*guiManager_,get_hadjustment(),
		        get_vadjustment());
		/*auto vc1=Gtk::manage(new GTK_ViewContainer(
		                         get_hadjustment(),
		                         get_vadjustment(),
		                         std::move(notebook_),this)
		                    );

		auto vc2=Gtk::manage(new GTK_ViewContainer(get_hadjustment(),get_vadjustment(),
		                     this));
		*/
		//Create the presenters of the container
		/*auto vcp1=std::unique_ptr<IViewContainerPresenter>(
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
		*/
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
/*
void GTK_ViewContainer::popOutView(IView& view) {
	if(!isTopLevel())
		return;
	removeView(view);
	//GUIManager::getInstance().moveViewToNewWindow(view);
}
*/
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

/*
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
*/
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
		//TODO:check for views
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

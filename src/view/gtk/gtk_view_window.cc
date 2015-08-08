#include <gtk_view_window.h>

#include <gtkmm/builder.h>
#include <glibmm/refptr.h>
#include <gtkmm/viewport.h>
#include <gtkmm/adjustment.h>

#include <string>
#include <memory>
#include <iostream>

#include <presenter/interfaces/i_view_window_presenter.h>
#include <presenter/interfaces/i_view_container_presenter.h>
#include <view/interfaces/i_view.h>

#include <gtk_view_container.h>
#include <view_container_presenter.h>
#include <view/view_type.h>
#include <gtk_view_container_factory.h>
#include <gtk_logger.h>

INIT_LOCATION;

namespace erebus  {


const std::string 	GTK_ViewWindow::CLASSNAME="GTK_ViewWindow";
GTK_ViewWindow::GTK_ViewWindow(BaseObjectType* cobject,
                               const Glib::RefPtr<Gtk::Builder>& refBuilder
                              ):GTK_Window(cobject) {
	LOG_CONSTRUCTOR;

	isInitialized_=false;

	base_=nullptr;
	refBuilder->get_widget("basic_viewport",base_);
	LOG_ASSERT_GTK(base_!=nullptr);

	setPreferredSize(600,400);

}

void GTK_ViewWindow::initialize(IGUIManager& manager) {
	LOG_ASSERT(gtk_l::get(),!isInitialized_);

	setGUIManager(manager);


	basicViewContainer_=std::move(GTK_ViewContainerFactory::createViewContainer<ViewContainerPresenter>
	                              (manager,
	                               base_->get_hadjustment(),
	                               base_->get_vadjustment()));

	base_->add(*(basicViewContainer_.get()));

	show_all_children();

	isInitialized_=true;
}

GTK_ViewWindow::~GTK_ViewWindow() {
	LOG_DESTRUCTOR;
}



std::string GTK_ViewWindow::classname() {
	return "GTK_ViewWindow";
}

void GTK_ViewWindow::setPresenter(std::unique_ptr<IViewWindowPresenter>
                                  presenter) {
	presenter_=std::move(presenter);
}

void GTK_ViewWindow::addView(IView& view) {
	LOG_ASSERT_GTK(isInitialized_);
	LOG_ASSERT_GTK(basicViewContainer_.get()!=nullptr);

	if(basicViewContainer_->isTopLevel())
		basicViewContainer_->addView(view);
}

bool GTK_ViewWindow::containsWidget(std::size_t id) {
	LOG_ASSERT(gtk_l::get(),isInitialized_);
	LOG_ASSERT(gtk_l::get(),basicViewContainer_.get()!=nullptr);

	if(basicViewContainer_->getID()==id)
		return true;

	return basicViewContainer_->containsWidget(id);
}

IGUIObject* GTK_ViewWindow::getParentOf(std::size_t id) {
	if(!containsWidget(id))
		return nullptr;

	LOG_ASSERT(gtk_l::get(),isInitialized_);
	LOG_ASSERT(gtk_l::get(),basicViewContainer_.get()!=nullptr);

	if(basicViewContainer_->getID()==id)
		return this;
	return basicViewContainer_->getParentOf(id);
}

}//namespace erebus

#include <gtk_empty_view.h>

#include <gtkmm.h>

#include <memory>

#include <presenter/interfaces/i_empty_view_presenter.h>
#include <presenter/interfaces/i_view_presenter.h>

#include <presenter/empty_view_presenter.h>

#include <gtk_view.h>
#include <gtk_logger.h>

INIT_LOCATION;

namespace erebus {

const std::string 	GTK_EmptyView::CLASSNAME="GTK_EmptyView";

GTK_EmptyView::GTK_EmptyView(BaseObjectType* cobject,
                             const Glib::RefPtr<Gtk::Builder>& refBuilder)
	:GTK_View(cobject,refBuilder) {
	Gdk::RGBA color("red");
	color.set_rgba(0.8,0.8,0.8);
	override_background_color(color);

	BOOST_LOG_SEV(gtk_l::get(),normal)<<LOCATION<<"Constructing "<<classname()<<" '"<<getID()<<"'";
}


GTK_EmptyView::~GTK_EmptyView() {
	BOOST_LOG_SEV(gtk_l::get(),normal)<<LOCATION<<"Destructing "<<classname()<<" '"<<getID()<<"'";

}
std::string GTK_EmptyView::classname() {
	return CLASSNAME;
}

std::size_t GTK_EmptyView::getID() {
	return reinterpret_cast<std::size_t>(this);
}

void GTK_EmptyView::setPresenter(std::unique_ptr<IEmptyViewPresenter>
                                 presenter) {
	presenter_=std::move(presenter);
}
/*
IViewPresenter& GTK_EmptyView::getPresenter() const {
	return *(presenter_.get());
}


void GTK_EmptyView::showContextMenu() {
	GTK_View::showContextMenu();
}


void GTK_EmptyView::close() {
	BOOST_LOG_SEV(gtk_l::get(),normal)<<LOCATION<<"Closing empty view '"<<this<<"'";
	GTK_View::close();
}


void GTK_EmptyView::setParent(IViewContainer* container) {
	GTK_View::setParent(container);
}


IViewContainer* GTK_EmptyView::getParent() const {
	return GTK_View::getParent();
}


void GTK_EmptyView::popOut() {
	GTK_View::popOut();
}


void GTK_EmptyView::createContextMenu() {
	GTK_View::createContextMenu();

	auto empty = Gtk::manage(new Gtk::MenuItem("Empty Entry"));
	empty->set_sensitive(false);

	popupMenu_->prepend(*empty);

	popupMenu_->accelerate(*this);
	popupMenu_->show_all();
}*/
}//namespace erebus

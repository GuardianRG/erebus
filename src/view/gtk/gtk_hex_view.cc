#include <gtk_hex_view.h>

#include <presenter/interfaces/i_hex_view_presenter.h>
#include <presenter/interfaces/i_view_presenter.h>

#include <gtk_view.h>
#include <gtk_logger.h>

INIT_LOCATION;

namespace erebus {
const std::string GTK_HexView::CLASSNAME="GTK_HexView";

GTK_HexView::GTK_HexView(BaseObjectType* cobject,
                         const Glib::RefPtr<Gtk::Builder>& refBuilder):GTK_View(cobject,refBuilder) {
	BOOST_LOG_SEV(gtk_l::get(),normal)<<LOCATION<<"Creating hex view '"<<this<<"'";
}

GTK_HexView::~GTK_HexView() {

}

void GTK_HexView::setPresenter(std::unique_ptr<IHexViewPresenter> presenter) {
	presenter_=std::move(presenter);
}
/*
IViewPresenter& GTK_HexView::getPresenter() const {
	return *(presenter_.get());
}*/
std::string GTK_HexView::classname() {
	return CLASSNAME;
}

std::size_t GTK_HexView::getID() {
	return reinterpret_cast<std::size_t>(this);
}

/*
void GTK_HexView::showContextMenu() {
	GTK_View::showContextMenu();
}


void GTK_HexView::close() {
	BOOST_LOG_SEV(gtk_l::get(),normal)<<LOCATION<<"Closing hex view '"<<this<<"'";
	GTK_View::close();
}


void GTK_HexView::setParent(IViewContainer* container) {
	GTK_View::setParent(container);
}


IViewContainer* GTK_HexView::getParent() const {
	return GTK_View::getParent();
}


void GTK_HexView::popOut() {
	GTK_View::popOut();
}


void GTK_HexView::createContextMenu() {
	GTK_View::createContextMenu();
}*/
}//namespace erebus

#include <gtk_hex_view.h>

#include <presenter/interfaces/i_hex_view_presenter.h>
#include <presenter/interfaces/i_view_presenter.h>

#include <gtk_view.h>

namespace erebus {
GTK_HexView::GTK_HexView(Glib::RefPtr<Gtk::Adjustment> h_adjustment,Glib::RefPtr<Gtk::Adjustment> v_adjustment):GTK_View(h_adjustment,v_adjustment) {

}

GTK_HexView::~GTK_HexView() {

}

void GTK_HexView::setPresenter(IViewPresenter* presenter) {
	presenter_=static_cast<IHexViewPresenter*>(presenter);
	GTK_View::setPresenter(presenter);
}

std::string GTK_HexView::getTitle() {
	return GTK_View::getTitle();
}

void GTK_HexView::setTitle(std::string title) {
	GTK_View::setTitle(title);
}

void GTK_HexView::showContextMenu() {
	GTK_View::showContextMenu();
}


void GTK_HexView::close() {
	GTK_View::close();
}


void GTK_HexView::setParent(IViewContainer* container) {
	GTK_View::setParent(container);
}


IViewContainer* GTK_HexView::getParent() {
	return GTK_View::getParent();
}


void GTK_HexView::popOut() {
	GTK_View::popOut();
}


void GTK_HexView::createContextMenu() {
	GTK_View::createContextMenu();
}
}//namespace erebus
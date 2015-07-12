#include <gtk_empty_view.h>
#include <gtk_view.h>

#include <gtkmm.h>

namespace erebus {

	GTK_EmptyView::GTK_EmptyView(Glib::RefPtr<Gtk::Adjustment> h_adjustment,Glib::RefPtr<Gtk::Adjustment> v_adjustment):GTK_View(h_adjustment,v_adjustment) {
	override_background_color(Gdk::RGBA("green"));
}
GTK_EmptyView::~GTK_EmptyView() {
	
}
}
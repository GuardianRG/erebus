#include <gtk_empty_view.h>

#include <gtkmm.h>

#include <gtk_view.h>


namespace erebus {

GTK_EmptyView::GTK_EmptyView(Glib::RefPtr<Gtk::Adjustment> h_adjustment,Glib::RefPtr<Gtk::Adjustment> v_adjustment):GTK_View(h_adjustment,v_adjustment) {
	Gdk::RGBA color("red");
	color.set_rgba(0.8,0.8,0.8);
	override_background_color(color);
}

GTK_EmptyView::~GTK_EmptyView() {

}
}//namespace erebus
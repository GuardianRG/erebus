#include <gtkmm.h>

#include <gtk_file_hex_view.h>

namespace erebus {
	
	GtkFileHexView::GtkFileHexView(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder): Gtk::Viewport(cobject) {
	
}
	
	GtkFileHexView::~GtkFileHexView() {
		
	}
	
}
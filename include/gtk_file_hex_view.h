#pragma once

#include <gtkmm.h>

namespace erebus {
	
class GtkFileHexView : public Gtk::Viewport {
public:
	GtkFileHexView(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder);
	
	GtkFileHexView(const GtkFileHexView &obj)=delete;
	
	~GtkFileHexView();



};	
	
	
}
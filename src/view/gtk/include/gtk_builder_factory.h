#pragma once

#include <gtkmm.h>
#include <string>

namespace erebus {
class GTK_BuilderFactory {
public:
	static Glib::RefPtr<Gtk::Builder> getBuilder(std::string path);
};	
}
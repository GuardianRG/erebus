#pragma once

#include <gtkmm/builder.h>
#include <glibmm/refptr.h>

#include <string>

namespace erebus {

/**
 * This class cotains a factory methode for createing
 * a builder for a .glade file.
 */
class GTK_BuilderFactory {
	GTK_BuilderFactory();

  public:
	~GTK_BuilderFactory() {}

	/**
	 * Creates a builder from the file on the given path.
	 *
	 * @param path path to the glade file to load
	 * @return a builder which containes the items of the file
	 */
	static Glib::RefPtr<Gtk::Builder> getBuilder(std::string path);
};
}//namespace erebus

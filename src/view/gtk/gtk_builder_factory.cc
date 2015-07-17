#include <gtk_builder_factory.h>

#include <gtkmm.h>
#include <string>

namespace erebus {

Glib::RefPtr<Gtk::Builder> GTK_BuilderFactory::getBuilder(std::string path) {
	Glib::RefPtr<Gtk::Builder> refBuilder = Gtk::Builder::create();

	refBuilder->add_from_file(path);

	return refBuilder;
}

}//namespace erebus
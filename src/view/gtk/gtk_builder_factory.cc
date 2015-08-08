#include <gtk_builder_factory.h>

#include <gtkmm/builder.h>
#include <glibmm/refptr.h>
#include <glibmm/fileutils.h>
#include <glibmm/markup.h>

#include <string>

#include <gtk_logger.h>

INIT_LOCATION;

namespace erebus {

Glib::RefPtr<Gtk::Builder> GTK_BuilderFactory::getBuilder(std::string path) {
	Glib::RefPtr<Gtk::Builder> refBuilder = Gtk::Builder::create();

	try {
		refBuilder->add_from_file(path);
	} catch(const Glib::FileError& ex) {
		LOG_GTK(error) << "FileError: " << ex.what() << std::endl;
		throw;
	} catch(const Glib::MarkupError& ex) {
		LOG_GTK(error) << "MarkupError: " << ex.what() << std::endl;
		throw;
	} catch(const Gtk::BuilderError& ex) {
		LOG_GTK(error) << "BuilderError: " << ex.what() << std::endl;
		throw;
	}

	return refBuilder;
}

}//namespace erebus

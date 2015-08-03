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
		BOOST_LOG_SEV(gtk_l::get(),error) << "FileError: " << ex.what() << std::endl;
		throw;
	} catch(const Glib::MarkupError& ex) {
		BOOST_LOG_SEV(gtk_l::get(),error) << "MarkupError: " << ex.what() << std::endl;
		throw;
	} catch(const Gtk::BuilderError& ex) {
		BOOST_LOG_SEV(gtk_l::get(),error) << "BuilderError: " << ex.what() << std::endl;
		throw;
	}

	return refBuilder;
}

}//namespace erebus

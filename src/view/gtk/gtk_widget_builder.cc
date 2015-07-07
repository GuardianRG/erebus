#include <gtkmm.h>

#include <gtk_widget_builder.h>
#include <gtk_file_hex_view.h>
#include <gtk_main_view.h>

namespace erebus {
	
Glib::RefPtr<Gtk::Builder> GtkWidgetBuilder::loadWidget(std::string path) {
	Glib::RefPtr<Gtk::Builder> refBuilder = Gtk::Builder::create();
	
	refBuilder->add_from_file(path);
	
	return refBuilder;
}

GtkMainView* GtkWidgetBuilder::buildMainView() {
	GtkMainView* w;
	Glib::RefPtr<Gtk::Builder> builder=GtkWidgetBuilder::loadWidget("resources/main_view.glade");
	builder->get_widget_derived("main_view", w);
	return w;
}

GtkFileHexView* GtkWidgetBuilder::buildFileHexView() {
	GtkFileHexView* w;
	Glib::RefPtr<Gtk::Builder> builder=loadWidget("resources/file_hex_view.glade");
	builder->get_widget_derived("file_hex_view", w);
	return w;
}

}
#include <gtkmm.h>

#include <gtk_view_builder.h>
#include <gtk_main_view.h>

namespace erebus {

GtkMainView* GtkViewBuilder::buildMainView() {
	//path to the template for main_view
	std::string viewTemplate="resources/main_view.glade";
	
	//Parse template
	Glib::RefPtr<Gtk::Builder> refBuilder = Gtk::Builder::create();
	try {
		refBuilder->add_from_file(viewTemplate);
	} catch(...) {
		return nullptr;
	}
	
	//create MainView
	erebus::GtkMainView* w;
	refBuilder->get_widget_derived("main_view", w);
	
	return w;
}	
	
}
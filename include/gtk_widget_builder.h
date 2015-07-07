#pragma once

#include <gtkmm.h>

#include <string>

#include <gtk_main_view.h>
#include <gtk_file_hex_view.h>

namespace erebus {

/**
 * This class provides methods to create the concrete views.
 */
class GtkWidgetBuilder {
	static Glib::RefPtr<Gtk::Builder> loadWidget(std::string path);
  public:
	/**
	 * Creates a GtkMainView.
	 *
	 * @return pointer to the GtkMainView
	 */
	static GtkMainView* buildMainView();
	
	static GtkFileHexView* buildFileHexView();
	
};

}
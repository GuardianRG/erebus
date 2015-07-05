#pragma once

#include <gtk_main_view.h>

namespace erebus {

	/**
	 * This class provides methods to create the concrete views.
	 */
class GtkViewBuilder {
	
public:
	/**
	 * Creates a GtkMainView.
	 * 
	 * @return pointer to the GtkMainView
	 */
	static GtkMainView* buildMainView();
};

}
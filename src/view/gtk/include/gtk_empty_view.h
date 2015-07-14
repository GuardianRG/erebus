#pragma once

#include <gtkmm.h>

#include <gtk_view.h>


namespace erebus {

/**
 * This class is a empty view.
 *
 * This view does nothing except of being a prove of concept.
 * Kind of a dummy.
 *
 * See GTK_View
 */
class GTK_EmptyView:public GTK_View  {
  public:
	/**
	 * Constructor.
	 *
	 * This constructor is needed to create a valid View.
	 */
	GTK_EmptyView(Glib::RefPtr<Gtk::Adjustment> h_adjustment,Glib::RefPtr<Gtk::Adjustment> v_adjustment);

	/**
	 * Destructor.
	 */
	~GTK_EmptyView();

	void createContextMenu() override;


};

}//namespace erebus
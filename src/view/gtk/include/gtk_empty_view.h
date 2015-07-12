#pragma once
#include <gtkmm.h>

#include <gtk_view.h>


namespace erebus {

class GTK_EmptyView:public GTK_View  {
  public:
	  GTK_EmptyView(Glib::RefPtr<Gtk::Adjustment> h_adjustment,Glib::RefPtr<Gtk::Adjustment> v_adjustment);
	~GTK_EmptyView();


};

}
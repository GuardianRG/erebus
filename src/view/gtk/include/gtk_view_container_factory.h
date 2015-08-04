#pragma once

#include <memory>
#include <gtkmm/adjustment.h>
#include <gtkmm/notebook.h>
#include <glibmm/refptr.h>

namespace erebus {
class IViewContainerPresenter;
class GTK_ViewContainer;
}

namespace erebus {
class GTK_ViewContainerFactory {
	GTK_ViewContainerFactory();
  public:
	~GTK_ViewContainerFactory();

	static std::unique_ptr<GTK_ViewContainer> createViewContainer(
	    std::unique_ptr<IViewContainerPresenter> presenter,
	    Glib::RefPtr<Gtk::Adjustment> h_adjustment,
	    Glib::RefPtr<Gtk::Adjustment> v_adjustment,
	    std::unique_ptr<Gtk::Notebook> notebook
	);

	static std::unique_ptr<GTK_ViewContainer> createViewContainer(
	    std::unique_ptr<IViewContainerPresenter> presenter,
	    Glib::RefPtr<Gtk::Adjustment> h_adjustment,
	    Glib::RefPtr<Gtk::Adjustment> v_adjustment
	);

	static std::unique_ptr<GTK_ViewContainer> createViewContainer(
	    Glib::RefPtr<Gtk::Adjustment> h_adjustment,
	    Glib::RefPtr<Gtk::Adjustment> v_adjustment,
	    std::unique_ptr<Gtk::Notebook> notebook
	);

	static std::unique_ptr<GTK_ViewContainer> createViewContainer(
	    Glib::RefPtr<Gtk::Adjustment> h_adjustment,
	    Glib::RefPtr<Gtk::Adjustment> v_adjustment
	);

};


}//namespace erebus

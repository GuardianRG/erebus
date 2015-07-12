#pragma once

#include <gtkmm.h>

#include <view/interfaces/i_view.h>
#include <presenter/interfaces/i_presenter.h>
#include <presenter/interfaces/i_view_presenter.h>
#include <string>
#include <view/interfaces/i_view_container.h>
#include <gtk_view_container.h>

namespace erebus {

class GTK_View:public Gtk::Viewport,public IView {
	IViewPresenter*	presenter_;
	GTK_ViewContainer*	container_;
	
	std::string 	title_;
	
	Gtk::Menu*	popupMenu_;
	int buffer_;
	void init();
	
  public:
	  GTK_View(Glib::RefPtr<Gtk::Adjustment> h_adjustment,Glib::RefPtr<Gtk::Adjustment> v_adjustment);
	GTK_View(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder);

	~GTK_View();
	
	bool on_button_press_event(GdkEventButton *ev) override;
	void setPresenter(IPresenter* presenter) override;
	std::string getTitle() override;
	void setTitle(std::string title)override;
	void setViewContainer(GTK_ViewContainer* container);
	virtual void createContextMenu();
	void showContextMenu()override;
};

}
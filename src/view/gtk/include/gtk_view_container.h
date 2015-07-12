#pragma once

#include <gtkmm.h>

#include <view/interfaces/i_view_container.h>
#include <presenter/interfaces/i_view_container_presenter.h>
#include <view/interfaces/i_view.h>

namespace erebus {
class GTK_ViewContainer:public IViewContainer,public Gtk::Viewport {
	Gtk::Notebook*	notebook_;
	Gtk::Paned*	paned_;

	IViewContainerPresenter* presenter_;

	Gtk::Menu* 	popupMenu_;
	
	Glib::RefPtr<Gtk::Adjustment> h_adjustment_;
	Glib::RefPtr<Gtk::Adjustment> v_adjustment_;

	int buffer_;

	void split();

	void on_context_menu_split_view_horizontal_click();
	void on_context_menu_split_view_vertical_click();
	void on_context_menu_add_view_empty_view_click();
  public:
	GTK_ViewContainer(Glib::RefPtr<Gtk::Adjustment> h_adjustment,Glib::RefPtr<Gtk::Adjustment> v_adjustment,Gtk::Notebook* notebook);
	~GTK_ViewContainer();

	void setPresenter(IViewContainerPresenter* presenter)override;

	void splitHorizontal() override;
	void splitVertical() override;
	void showTabs(bool showTabs) override;

	bool isEmpty()override;

	void showContextMenu()override;
	
	void buildContextMenu(Gtk::Menu* menu);
	
	void addView(IView* view)override;
	
	void addView(ViewType type)override;
	bool isTopLevel()override;

	bool on_button_press_event(GdkEventButton *ev) override;
};
}
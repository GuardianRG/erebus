#pragma once

#include <gtkmm.h>

#include <view/interfaces/i_view_container.h>
#include <presenter/interfaces/i_view_container_presenter.h>

namespace erebus {
class GTK_ViewContainer:public IViewContainer,public Gtk::Viewport {
	Gtk::Notebook*	notebook_;
	Gtk::Paned*	paned_;

	IViewContainerPresenter* presenter_;

	Gtk::Menu 	popupMenu_;

	int buffer_;

	void split();

	void on_context_menu_split_view_horizontal_click();
	void on_context_menu_split_view_vertical_click();
  public:
	GTK_ViewContainer(Glib::RefPtr<Gtk::Adjustment> h_adjustment,Glib::RefPtr<Gtk::Adjustment> v_adjustment,Gtk::Notebook* notebook);
	~GTK_ViewContainer();

	void setPresenter(IViewContainerPresenter* presenter)override;

	void splitHorizontal() override;
	void splitVertical() override;
	void showTabs(bool showTabs) override;

	bool isTopLevelContainer()override;

	void showContextMenu()override;

	bool on_button_press_event(GdkEventButton *ev) override;
};
}
#pragma once

#include <gtkmm.h>

#include <view/interfaces/i_view.h>
#include <presenter/interfaces/i_presenter.h>
#include <presenter/interfaces/i_view_presenter.h>

namespace erebus {
	
	class GTK_View:public Gtk::Viewport,public IView {
		IViewPresenter*	presenter_;
		
		IView*		parent_;
		
		Gtk::Menu 	popupMenu_;
		
		int buffer_;
		
		void on_popup_menu_view_split_view_click();
	public:
		GTK_View(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder);
		~GTK_View();
		
		bool on_button_press_event(GdkEventButton *ev) override;
		
		void showContextMenu() override;
		
		void splitView() override;
		
		void addContextMenuItem(Gtk::MenuItem& child);
		
		void buildContextMenu();
		
		void setPresenter(IPresenter* presenter) override;
		
		void setParent(IView* parent) override;
	};
	
}
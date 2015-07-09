#include <gtk_view.h>

#include <gtkmm.h>

#include <view/interfaces/i_view.h>
#include <presenter/interfaces/i_presenter.h>
#include <presenter/interfaces/i_view_presenter.h>
#include <iostream>

namespace erebus {
	GTK_View::GTK_View(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder): Gtk::Viewport(cobject) {
		add_events(Gdk::BUTTON_PRESS_MASK );
		#ifndef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
		signal_button_press_event().connect(sigc::mem_fun(*this, &GTK_View::on_button_press_event), false);
		#endif
		
	}
	GTK_View::~GTK_View() {
		delete presenter_;
	}
	
	bool GTK_View::on_button_press_event(GdkEventButton* event) {
		bool return_value = false;
		
		
		
		return_value = Viewport::on_button_press_event(event);
		
		if( (event->type == GDK_BUTTON_PRESS))
		{
			switch(event->button) {
				case 3:
					presenter_->on_right_button_click();
					break;
				case 1:
					presenter_->on_left_button_click();
					break;
				default:;
			};
			
		}
		
		return return_value;
	}
	
	void GTK_View::setParent(IView* parent) {
		parent_=parent;
	}
	
	void GTK_View::splitView() {
		
	}
	void GTK_View::setPresenter(IPresenter* presenter) {
		presenter_=static_cast<IViewPresenter*>(presenter);
	}
	void GTK_View::showContextMenu() {
		
	}
}
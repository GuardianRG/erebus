#include <gtk_view.h>

#include <gtkmm.h>

#include <assert.h>

#include <view/interfaces/i_view.h>
#include <presenter/interfaces/i_presenter.h>
#include <presenter/interfaces/i_view_presenter.h>


namespace erebus {

GTK_View::GTK_View(Glib::RefPtr<Gtk::Adjustment> h_adjustment,Glib::RefPtr<Gtk::Adjustment> v_adjustment):Gtk::Viewport(h_adjustment,v_adjustment) {
	init();
}

GTK_View::GTK_View(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder): Gtk::Viewport(cobject) {
	init();
}

GTK_View::~GTK_View() {
	delete popupMenu_;
}


void GTK_View::init() {

	add_events(Gdk::BUTTON_PRESS_MASK );

#ifndef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
	signal_button_press_event().connect(sigc::mem_fun(*this, &GTK_View::on_button_press_event), false);
#endif

	title_="";
	presenter_=nullptr;
	container_=nullptr;
	popupMenu_=nullptr;
}

void GTK_View::setPresenter(IPresenter* presenter) {
	presenter_=static_cast<IViewPresenter*>(presenter);
}
void GTK_View::setTitle(std::string title) {
	title_=title;
}

std::string GTK_View::getTitle() {
	return title_;
}

void GTK_View::sanityCheck() {
	assert( presenter_!=nullptr && "No presenter set for GTK_View");
	assert( container_!=nullptr && "No view container set for GTK_View");
}

void GTK_View::setViewContainer(IViewContainer* container) {
	container_=static_cast<GTK_ViewContainer*>(container);
}

bool GTK_View::on_button_press_event(GdkEventButton *ev) {
	sanityCheck();

	bool return_value = false;

	return_value = Viewport::on_button_press_event(ev);

	if( (ev->type == GDK_BUTTON_PRESS)) {
		switch(ev->button) {
		case 3:
			timeBuffer_=ev->time;
			clickBuffer_=3;
			presenter_->on_right_button_click();
			break;
		case 1:
			timeBuffer_=ev->time;
			clickBuffer_=1;
			presenter_->on_left_button_click();
			break;
		default:
			;
		};

	}
	return return_value;
}

IViewContainer* GTK_View::getViewContainer() {
	return container_;
}


void GTK_View::createContextMenu() {
	sanityCheck();

	delete popupMenu_;
	popupMenu_=new Gtk::Menu;

	container_->buildContextMenu(popupMenu_);

	popupMenu_->accelerate(*this);
	popupMenu_->show_all();
}
void GTK_View::showContextMenu() {
	assert(popupMenu_!=nullptr&&"No popup menus et for GTK_View");

	popupMenu_->popup(clickBuffer_,timeBuffer_);
}
}//namespace erebus
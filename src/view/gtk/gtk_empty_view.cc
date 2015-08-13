#include <gtk_empty_view.h>

#include <gtkmm/builder.h>
#include <glibmm/refptr.h>

#include <memory>

#include <i_empty_view_presenter.h>
#include <i_view_presenter.h>
#include <empty_view_presenter.h>
#include <gtk_view.h>
#include <gtk_logger.h>
#include <view_type.h>

INIT_LOCATION;

namespace erebus {

const std::string 	GTK_EmptyView::CLASSNAME="GTK_EmptyView";

GTK_EmptyView::GTK_EmptyView(BaseObjectType* cobject,
                             const Glib::RefPtr<Gtk::Builder>& refBuilder)
	:GTK_View(cobject) {
	LOG_CONSTRUCTOR;

	Gdk::RGBA color("red");
	color.set_rgba(0.8,0.8,0.8);
	override_background_color(color);

}


GTK_EmptyView::~GTK_EmptyView() {
	LOG_DESTRUCTOR;

}
std::string GTK_EmptyView::classname() {
	return CLASSNAME;
}

std::size_t GTK_EmptyView::getID() {
	return reinterpret_cast<std::size_t>(this);
}

void GTK_EmptyView::setPresenter(std::unique_ptr<IEmptyViewPresenter>
                                 presenter) {
	LOG_ASSERT_GTK(presenter.get()!=nullptr);

	presenter_=std::move(presenter);
}

}//namespace erebus

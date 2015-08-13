#include <gtk_hex_view.h>

#include <gtkmm/builder.h>
#include <glibmm/refptr.h>

#include <i_hex_view_presenter.h>
#include <i_view_presenter.h>

#include <gtk_view.h>
#include <gtk_logger.h>
#include <view_type.h>

INIT_LOCATION;

namespace erebus {
	
const std::string GTK_HexView::CLASSNAME="GTK_HexView";

GTK_HexView::GTK_HexView(BaseObjectType* cobject,
                         const Glib::RefPtr<Gtk::Builder>& refBuilder):GTK_View(cobject) {
	LOG_CONSTRUCTOR;
	
	Gdk::RGBA color("red");
	color.set_rgba(1.0,1.0,1.0);
	override_background_color(color);
}

GTK_HexView::~GTK_HexView() {
	LOG_DESTRUCTOR;
}

void GTK_HexView::setPresenter(std::unique_ptr<IHexViewPresenter> presenter) {
	LOG_ASSERT_GTK(presenter.get()!=nullptr);
	
	presenter_=std::move(presenter);
}

std::string GTK_HexView::classname() {
	return CLASSNAME;
}

std::size_t GTK_HexView::getID() {
	return reinterpret_cast<std::size_t>(this);
}

}//namespace erebus

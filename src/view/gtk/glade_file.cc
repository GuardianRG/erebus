#include <glade_file.h>

#include <string>

#include <view/view_type.h>
#include <view/window_type.h>
#include <gtk_logger.h>

INIT_LOCATION;

namespace erebus {
GladeFile::GladeFile() {

}

GladeFile::~GladeFile() {

}

std::string GladeFile::getFile(ViewType type) {
	switch(type) {
	case ViewType::EMPTY_VIEW:
		return "resources/empty_view.glade";
		break;
	default:
		LOG_ASSERT(gtk_l::get(),false);
	}
	return "";
}

std::string GladeFile::getFile(WindowType type) {
	switch(type) {
	case WindowType::MAIN_WINDOW:
		return "resources/main_window.glade";
		break;
	case WindowType::VIEW_WINDOW:
		return "resources/view_window.glade";
		break;
	default:
		LOG_ASSERT(gtk_l::get(),false);
	}
	return "";
}

}//namespace erebus

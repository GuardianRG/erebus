#include <glade_file.h>

#include <string>

#include <view_type.h>
#include <window_type.h>
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
		//The default case gets asserted because if control flow comes to this
		//it means i forgot a case.
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
		//The default case gets asserted because if control flow comes to this
		//it means i forgot a case.
		LOG_ASSERT(gtk_l::get(),false);
	}
	return "";
}

}//namespace erebus

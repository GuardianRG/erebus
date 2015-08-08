#include <gtk_window_factory.h>

#include <memory>


#include <presenter/interfaces/i_main_window_presenter.h>
#include <presenter/interfaces/i_view_window_presenter.h>

#include <gtk_main_window.h>
#include <presenter/main_window_presenter.h>
#include <presenter/view_window_presenter.h>
#include <glade_file.h>
#include <gtk_logger.h>
#include <gtk_builder_factory.h>
#include <view/window_type.h>
#include <gtk_view_window.h>

INIT_LOCATION;

namespace erebus {
class IGUIManager;
}

namespace erebus {
GTK_WindowFactory::GTK_WindowFactory() {
}

GTK_WindowFactory::~GTK_WindowFactory() {

}

}//namespace erebus

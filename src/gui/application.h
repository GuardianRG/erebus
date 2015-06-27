#pragma once

#include <gtkmm/application.h>

#include "frames/main_frame.h"


namespace erebus {
	namespace gui {
		
		class Application {
			Glib::RefPtr<Gtk::Application> app_;
			
			
		public:
			
			Application(int argc, char *argv[]);
			
			~Application();
			
			void run();
			
			
		};
	}
}
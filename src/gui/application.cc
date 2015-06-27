#include <gtkmm/application.h>

#include "application.h"
#include "frames/main_frame.h"

namespace erebus {
	namespace gui {
		
		Application::Application(int argc,char *argv[]) {
			app_=Gtk::Application::create(argc,argv,
					"org.suppengeist.erebus");
		}
		Application::~Application() {
			
		}
		
		void Application::run() {
			MainFrame mf;
			app_->run(mf);
		}
		
		
	}
}
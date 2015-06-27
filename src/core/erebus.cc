#include <gtkmm.h>

#include "../gui/frames/main_frame.h"

int main(int argc, char *argv[]) {
	Glib::RefPtr<Gtk::Application> app =
	Gtk::Application::create(argc, argv,
				 "org.suppengeist.erebus");
	
	erebus::MainFrame mf("erebus",true);
	app->run(mf);
	
	return 0;
}
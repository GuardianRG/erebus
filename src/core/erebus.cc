#include <gtkmm.h>

#include "../gui/application.h"

int main(int argc, char *argv[]) {
	erebus::gui::Application appli(argc,argv);
	appli.run();
	
	return 0;
}
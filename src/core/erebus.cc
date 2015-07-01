#include <gtkmm.h>
#include <main_view.h>
#include <main_view_presenter.h>

int main(int argc, char *argv[]) {
	Glib::RefPtr<Gtk::Application> app =
	Gtk::Application::create(argc, argv,
				 "org.suppengeist.erebus");
	
	erebus::MainView mf;
	erebus::MainViewPresenter mvp(&mf);
	app->run(mf);
	
	return 0;
}
#include <gtkmm.h>

#include <iostream>

#include <main_view.h>
#include <main_view_presenter.h>
#include <model.h>

int main(int argc, char *argv[]) {
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
	
	Glib::RefPtr<Gtk::Builder> refBuilder = Gtk::Builder::create();
	try
	{
		refBuilder->add_from_file("resources/main_view.glade");
	}
	catch(const Glib::FileError& ex)
	{
		std::cerr << "FileError: " << ex.what() << std::endl;
		return 1;
	}
	catch(const Glib::MarkupError& ex)
	{
		std::cerr << "MarkupError: " << ex.what() << std::endl;
		return 1;
	}
	catch(const Gtk::BuilderError& ex)
	{
		std::cerr << "BuilderError: " << ex.what() << std::endl;
		return 1;
	}
	
	
	erebus::MainView* w;
	refBuilder->get_widget_derived("window1", w);
	erebus::Model m;
	
	erebus::MainViewPresenter p;
	p.setView(w);
	p.setModel(&m);
	w->setPresenter(&p);
	
	if(w) {
		app->run(*w);
	}
	
	return 0;
}
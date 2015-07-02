#include <gtkmm/window.h>

#include <boost/signals2.hpp>
#include <boost/function.hpp>

#include <main_view.h>

namespace erebus {
MainView::MainView() :menuBar_(Gtk::ORIENTATION_VERTICAL) {
	
	set_default_size(800,600);
	
	initFrame();
}

MainView::~MainView() {

}

void MainView::initFrame() {
	add(menuBar_);

	Glib::RefPtr<Gio::SimpleActionGroup> refActionGroup = Gio::SimpleActionGroup::create();

	refActionGroup->add_action("open",sigc::mem_fun(*this,&MainView::on_menu_file_open));
	refActionGroup->add_action("quit",sigc::mem_fun(*this,&MainView::on_menu_file_quit));

	insert_action_group("mainframemenubar", refActionGroup);

	m_refBuilder = Gtk::Builder::create();

	Glib::ustring ui_info=
	    "<interface>"
	    "	<menu id='menuBarMainFrame'>"
	    "		<submenu>"
	    "			<attribute name='label' translatable='yes'>File</attribute>"
	    "			<section>"
	    "				<item>"
	    "					<attribute name='label' translatable='yes'>Open File</attribute>"
	    "					<attribute name='action'>mainframemenubar.open</attribute>"
	    "				</item>"
	    "			</section>"
	    "			<section>"
	    "				<item>"
	    "					<attribute name='label' translatable='yes'>Quit</attribute>"
	    "					<attribute name='action'>mainframemenubar.quit</attribute>"
	    "				</item>"
	    "			</section>"
	    "		</submenu>"
	    "		<submenu>"
	    "			<attribute name='label' translatable='yes'>Help</attribute>"
	    "		</submenu>"
	    "	</menu>"
	    "</interface>";

	try {
		m_refBuilder->add_from_string(ui_info);
	}
	catch(const Glib::Error& ex) {
		//std::cerr << "building menus failed: " <<  ex.what();
	}

	Glib::RefPtr<Glib::Object> object = m_refBuilder->get_object("menuBarMainFrame");

	Glib::RefPtr<Gio::Menu> gmenu =	Glib::RefPtr<Gio::Menu>::cast_dynamic(object);
	if(!gmenu)
		g_warning("GMenu not found");

	Gtk::MenuBar* pMenubar = Gtk::manage(new Gtk::MenuBar(gmenu));
	menuBar_.pack_start(*pMenubar, Gtk::PACK_SHRINK);

	show_all_children();
}

void MainView::on_menu_file_open() {

}

void MainView::on_menu_file_quit() {
	quit_();
}

void MainView::registerFunctionQuit(boost::function<void()> func) {
	quit_.connect(func);
}

void MainView::setPreferredSize(int width,int height) {
	set_default_size(width,height);
}

void MainView::setTitle(std::string title) {
	set_title(title);
}

}
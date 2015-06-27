#include <gtkmm/window.h>

#include <iostream>

#include "main_frame.h"

namespace erebus {
		MainFrame::MainFrame() : MainFrame("erebus",false) {
			
		}
		MainFrame::MainFrame(std::string title,bool maximized):menuBar_(Gtk::ORIENTATION_VERTICAL) {
			set_default_size(800,600);
			set_title(title);
			
			unmaximize();
			if(maximized)
				maximize();
			
			initFrame();
			
		}
		
		MainFrame::~MainFrame() {
			
		}
		
		void MainFrame::initFrame() {
			add(menuBar_);
			
			Glib::RefPtr<Gio::SimpleActionGroup> refActionGroup = Gio::SimpleActionGroup::create();
			
			refActionGroup->add_action("open",sigc::mem_fun(*this,&MainFrame::on_menu_file_open));
			refActionGroup->add_action("quit",sigc::mem_fun(*this,&MainFrame::on_menu_file_quit));
			
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
		
		void MainFrame::on_menu_file_open() {
			
		}
		
		void MainFrame::on_menu_file_quit() {
			hide();
		}
		
		void MainFrame::setPreferredSize(int width,int height) {
			set_default_size(width,height);
		}
		
		void MainFrame::setTitle(std::string title) {
			set_title(title);
		}
	
}
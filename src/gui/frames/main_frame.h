#pragma once

#include <string>

#include <gtkmm.h>

namespace erebus {
	namespace gui {
		
		class MainFrame : public Gtk::Window {
			
		public:
			MainFrame();
			MainFrame(std::string title,bool maximized);
			virtual ~MainFrame();
			
			void setPreferredSize(int width,int height);
			void setTitle(std::string);
			
		protected:
			
			Gtk::Box menuBar_;
			Glib::RefPtr<Gtk::Builder> m_refBuilder;
			
			void on_menu_file_open();
			void on_menu_file_quit();
			
		private:
			void initFrame();
			
			
		};
	}
}


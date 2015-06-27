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
			
			
		};
	}
}


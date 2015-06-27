#pragma once

#include <gtkmm/window.h>

namespace erebus {
	namespace gui {
		
		class MainFrame : public Gtk::Window {
		public:
			MainFrame();
			virtual ~MainFrame();
			
			void setPreferredSize(int width,int height);
			
		protected:
			
			
		};
	}
}


#include <gtkmm/window.h>

#include "main_frame.h"

namespace erebus {
	namespace gui {
		MainFrame::MainFrame() : MainFrame("erebus",false) {
			
		}
		MainFrame::MainFrame(std::string title,bool maximized) {
			set_default_size(800,600);
			set_title(title);
			
			unmaximize();
			if(maximized)
				maximize();
			
		}
		
		MainFrame::~MainFrame() {
			
		}
		
		void MainFrame::setPreferredSize(int width,int height) {
			set_default_size(width,height);
		}
		
		void MainFrame::setTitle(std::string title) {
			set_title(title);
		}
	}
}
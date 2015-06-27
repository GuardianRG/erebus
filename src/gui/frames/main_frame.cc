#include <gtkmm/window.h>

#include "main_frame.h"

namespace erebus {
	namespace gui {
		MainFrame::MainFrame() {
			set_default_size(800,600);
		}
		
		MainFrame::~MainFrame() {
			
		}
		
		void MainFrame::setPreferredSize(int width,int height) {
			set_default_size(width,height);
		}
	}
}
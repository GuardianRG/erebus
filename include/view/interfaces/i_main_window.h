#pragma once

#include <view/interfaces/i_window.h>
#include <presenter/interfaces/i_main_window_presenter.h>

namespace erebus {

/**
 * This class is the interface for a main window.
 */
class IMainWindow :virtual public IWindow {
  public:
	/**
	 * Destructor.
	 */
	virtual ~IMainWindow() {};
	
};

}//namespace erbus

#pragma once

#include <view/interfaces/i_window.h>

namespace erebus {

/**
 * This class is the interface for a main window.
 */
class IMainWindow : public IWindow {
  public:
	/**
	 * Destructor.
	 */
	virtual ~IMainWindow() {};
};

}//namespace erbus

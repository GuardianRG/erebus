#pragma once

#include <presenter/interfaces/i_window_presenter.h>

namespace erebus {

/**
 * This class is the interface for a main window presenter.
 */
class IMainWindowPresenter:public IWindowPresenter {
  public:
	/**
	 * Destructor.
	 */
	virtual ~IMainWindowPresenter() {}

};
}//namespace erbus
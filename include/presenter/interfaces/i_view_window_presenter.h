#pragma once

#include <presenter/interfaces/i_window_presenter.h>

namespace erebus {

/**
 * This class is the interface for a view window presenter.
 */
class IViewWindowPresenter:public IWindowPresenter {
  public:
	/**
	 * Destructor.
	 */
	virtual ~IViewWindowPresenter() {}
};
}//namespace erebus
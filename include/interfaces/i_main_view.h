#pragma once

#include <interfaces/i_view.h>

namespace erebus {

/**
 * The interface for the MainView.
 */
class IMainView: public IView {

  public:
	/**
	 * Destructor.
	 */
	virtual ~IMainView() {}
};


}//namespace erebus
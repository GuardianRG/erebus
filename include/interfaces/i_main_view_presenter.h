#pragma once

#include <string>

#include <interfaces/i_presenter.h>

namespace erebus {

/**
 * This is the interface for the presenter for the MainView.
 */
class IMainViewPresenter : public IPresenter {

  public:
	/**
	 * Destructor.
	 */
	virtual ~IMainViewPresenter() {}

	/**
	 * Gets called by MainView if a new file should get loaded.
	 *
	 * @param path pah to the file to read
	 */
	virtual void loadFile(std::string path)=0;
};

}//namespace erebus
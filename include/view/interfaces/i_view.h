#pragma once

#include <string>
#include <memory>

#include <view/interfaces/i_gui_object.h>

namespace erebus {

class IGUIManager;
enum class ViewType;

}

namespace erebus {

/**
 * This class is the base interface for every view.
 */
class IView:public IGUIObject {

  public:
	/**
	 * Destructor.
	 */
	virtual ~IView() {}

	/**
	 * Returns the title of the view.
	 *
	 * The title is the string that gets show e.g. in the tab's head.
	 *
	 * @return title of the view
	 */
	virtual std::string getTitle() const=0;

	/**
	 * Sets the title of the view.
	 *
	 * @param title new title for the view
	 */
	virtual void setTitle(const std::string& title)=0;

};

}//namespace erbus

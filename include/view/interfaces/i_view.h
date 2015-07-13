#pragma once

#include <string>

#include <view/interfaces/i_view.h>
#include <view/interfaces/i_view_container.h>

namespace erebus {
class IPresenter;

class IView {
  public:
	virtual ~IView() {}

	virtual void setPresenter(IPresenter* presenter)=0;
	virtual std::string getTitle()=0;
	/**
	 * Sets the title of the view.
	 *
	 * @param title new title of the view
	 */
	virtual void setTitle(std::string title)=0;
	virtual void showContextMenu()=0;
	virtual void setViewContainer(IViewContainer* container)=0;
};

}
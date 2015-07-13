#pragma once

//#include <view/interfaces/i_view.h>
#include <view/view_type.h>

namespace erebus {
class IView;
class IViewContainerPresenter;

class IViewContainer {
  public:
	virtual ~IViewContainer() {}

	virtual void setPresenter(IViewContainerPresenter* presenter)=0;

	virtual void splitHorizontal()=0;

	virtual void splitVertical()=0;

	virtual void showTabs(bool showTabs)=0;

	virtual bool isEmpty()=0;

	virtual bool isTopLevel()=0;

	virtual void showContextMenu()=0;

	virtual void addView(IView* view)=0;

	virtual void addView(ViewType type)=0;
};
}
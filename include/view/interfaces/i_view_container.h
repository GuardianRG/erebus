#pragma once


namespace erebus {
class IViewContainerPresenter;

class IViewContainer {
  public:
	virtual ~IViewContainer() {}

	virtual void setPresenter(IViewContainerPresenter* presenter)=0;

	virtual void splitHorizontal()=0;
	virtual void splitVertical()=0;
	virtual void showTabs(bool showTabs)=0;
	virtual bool isTopLevelContainer()=0;
	virtual void showContextMenu()=0;
};
}
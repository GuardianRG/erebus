#pragma once

#include <view/interfaces/i_view.h>


namespace erebus {
class IPresenter;

class IView {
public:
	virtual ~IView() {}
	
	virtual void showContextMenu()=0;
	
	virtual void setParent(IView *parent)=0;
	
	virtual void splitView()=0;
	
	virtual void setPresenter(IPresenter* presenter)=0;
};

}
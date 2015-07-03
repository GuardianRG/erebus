#pragma once

#include <string>



namespace erebus {
	class IPresenter;

class IView {
public:
	virtual ~IView() {}
	virtual void setTitle(std::string title)=0;
	virtual void setPreferredSize(int width, int height)=0;
	virtual void maximize()=0;
	virtual void unmaximize()=0;
	
	virtual void setPresenter(IPresenter* presenter)=0;
};

}
#pragma once


#include <string>

namespace erebus {

class IPresenter;

class IWindow {
  public:
	virtual ~IWindow() {};

	virtual void setPresenter(IPresenter* presenter)=0;

	virtual void setTitle(std::string title)=0;
	virtual void setPreferredSize(int width,int height)=0;
	virtual void maximize()=0;
	virtual void unmaximize()=0;
};

}
#pragma once

#include <string>

namespace erebus {

class IView {
public:
	virtual ~IView() {}
	virtual void setTitle(std::string title)=0;
	virtual void setPreferredSize(int width, int height)=0;
};

}
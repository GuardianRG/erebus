#pragma once

#include <string>

#include <interfaces/i_presenter.h>

namespace erebus {
	
class IMainViewPresenter : public IPresenter{
public:
	virtual ~IMainViewPresenter() {}
	virtual void loadFile(std::string path)=0;
};
}
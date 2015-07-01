#pragma once

#include <memory>

#include <interfaces/i_main_view.h>

namespace erebus {

class MainViewPresenter {
	IMainView* mainView_;
	
public:
	MainViewPresenter(IMainView* mainView);
	
protected:
	void onQuit();
};

}
#include <memory>

#include <iostream>

#include <main_view_presenter.h>
#include <boost/bind.hpp>

namespace erebus {
	
	MainViewPresenter::MainViewPresenter(IMainView* mainView): mainView_(mainView) {
		mainView_->registerFunctionQuit(boost::bind(&MainViewPresenter::onQuit,this));
	}
	
	void MainViewPresenter::onQuit() {
		std::cout<<"Hallo Welt";
	}
	
}
#include <memory>

#include <string>
#include <iostream>

#include <main_view_presenter.h>
#include <interfaces/i_view.h>
#include <interfaces/i_model.h>
#include <main_view.h>

namespace erebus {
	
	MainViewPresenter::MainViewPresenter() {
	}
	
	MainViewPresenter::~MainViewPresenter() {
		
	}
	
	void MainViewPresenter::setView(IView* view) {
		mainView_=dynamic_cast<MainView*>(view);
	}
	void MainViewPresenter::setModel(IModel* model) {
		model_=model;
	}
	void MainViewPresenter::loadFile(std::string path) {
		model_->loadFile(path);
	}
	
}
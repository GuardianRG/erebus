#include <memory>

#include <string>
#include <iostream>
#include <assert.h>

#include <main_view_presenter.h>
#include <interfaces/i_view.h>
#include <interfaces/i_model.h>
#include <interfaces/i_main_view.h>

namespace erebus {

MainViewPresenter::MainViewPresenter() {
}

MainViewPresenter::~MainViewPresenter() {

}

void MainViewPresenter::setView(IView* view) {
	mainView_=dynamic_cast<IMainView*>(view);
}

void MainViewPresenter::setModel(IModel* model) {
	model_=model;
}

void MainViewPresenter::loadFile(std::string path) {
	assert(model_!=nullptr);

	model_->loadFile(path);
}

void MainViewPresenter::showErrorMessage(std::string errorMsg) {
	assert(mainView_!=nullptr);

	mainView_->showErrorMessage(errorMsg);
}

}//namespace erebus
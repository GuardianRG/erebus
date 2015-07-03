#pragma once

#include <string>

#include <interfaces/i_main_view.h>
#include <interfaces/i_main_view_presenter.h>
#include <interfaces/i_view.h>
#include <interfaces/i_model.h>

namespace erebus {

class MainViewPresenter : public IMainViewPresenter{
	IMainView* mainView_;
	IModel* model_;
	
public:
	MainViewPresenter();
	~MainViewPresenter();
	
	void setView(IView* view) override;
	void setModel(IModel* model) override;
	void loadFile(std::string path) override;
};

}
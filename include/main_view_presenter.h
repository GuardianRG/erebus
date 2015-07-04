#pragma once

#include <string>

#include <interfaces/i_main_view.h>
#include <interfaces/i_main_view_presenter.h>
#include <interfaces/i_view.h>
#include <interfaces/i_model.h>

namespace erebus {

/**
 * A concrete MainViewPresenter
 */
class MainViewPresenter : public IMainViewPresenter {
	IMainView* 	mainView_;
	IModel* 	model_;

  public:
	/**
	 * Constructor.
	 */
	MainViewPresenter();

	/**
	 * Copy Constructor.
	 */
	MainViewPresenter(const MainViewPresenter &obj)=delete;

	/**
	 * Destructor.
	 */
	~MainViewPresenter();

	/**
	 * See IMainViewPresenter::setView(IView* view).
	 */
	void setView(IView* view) override;

	/**
	 * See IMainViewPresenter::setModel(IModel* model).
	 */
	void setModel(IModel* model) override;

	/**
	 * See IMainViewPresenter::loadFile(std::string path).
	 */
	void loadFile(std::string path) override;

	/**
	 * See IMainViewPresenter::showErrorMessage(std::string errorMessage).
	 */
	void showErrorMessage(std::string errorMessage);
};

}//namespace erebus
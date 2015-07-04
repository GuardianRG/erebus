#pragma once

#include <string>

#include <interfaces/i_view.h>
#include <interfaces/i_model.h>

namespace erebus {

/**
 * The base interface for every presenter.
 */
class IPresenter {

  public:
	/**
	 * Destructor.
	 */
	virtual ~IPresenter() {}

	/**
	 * Sets the view the presenter operats on.
	 */
	virtual void setView(IView* view)=0;

	/**
	 * Sets the model the presenter operates on.
	 */
	virtual void setModel(IModel* model)=0;

	/**
	 * Shows that an error has occured.
	 *
	 * @param errorMessage Error Message
	 */
	virtual void showErrorMessage(std::string errorMessage)=0;
};

}//namespace erebus
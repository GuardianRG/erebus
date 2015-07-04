#pragma once

#include <string>

namespace erebus {

//Forward declaration of IPresenter to avoid
//cyclic includation with i_presenter.h
class IPresenter;

/**
 * The base interface for every view.
 */
class IView {

  public:
	/**
	 * Destructor.
	 */
	virtual ~IView() {}

	/**
	 * Sets the title of the view.
	 *
	 * @param title the new title for the view
	 */
	virtual void setTitle(std::string title)=0;

	/**
	 * Sets the preferred size for the view.
	 *
	 * @param width the preferred width
	 * @param height the preferred height
	 */
	virtual void setPreferredSize(int width, int height)=0;

	/**
	 * Maximizes the view.
	 */
	virtual void maximize()=0;

	/**
	 * Unmaximizes the view.
	 */
	virtual void unmaximize()=0;

	/**
	 * Sets the presenter the view gets controlled with.
	 *
	 * @paran presenter the presenter
	 */
	virtual void setPresenter(IPresenter* presenter)=0;

	/**
	 * Shows that an error has occured.
	 *
	 * @param errorMsg Error Message
	 */
	virtual void showErrorMessage(std::string errorMsg)=0;
};

}//namespace erebus
#pragma once

#include <presenter/interfaces/i_main_window_presenter.h>
#include <view/interfaces/i_window.h>
#include <view/interfaces/i_main_window.h>

namespace erebus {

/**
 * This class is a concrete main window presenter.
 */
class MainWindowPresenter:public IMainWindowPresenter {
	IMainWindow*	mainWindow_;
  public:
	/**
	 * Constructor.
	 */
	MainWindowPresenter();

	/**
	 * Copy constructor.
	 *
	 * Deleted until needed.
	 */
	MainWindowPresenter(const MainWindowPresenter &obj)=delete;

	/**
	 * Destructor.
	 */
	virtual ~MainWindowPresenter();

	/**
	 * See IMainWindowPresenter::setWindow
	 */
	virtual void setWindow(IWindow* window) override;

	/**
	 * See IMainWindowPresenter::getWindow
	 */
	virtual IWindow* getWindow() const override;
};

}//namespace erbus

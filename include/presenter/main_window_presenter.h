#pragma once

#include <presenter/interfaces/i_main_window_presenter.h>
#include <view/interfaces/i_window.h>
#include <view/interfaces/i_main_window.h>

namespace erebus {
class MainWindowPresenter:public IMainWindowPresenter {
	IMainWindow*	mainWindow_;
  public:
	MainWindowPresenter();
	MainWindowPresenter(const MainWindowPresenter &obj)=delete;
	~MainWindowPresenter();

	void setWindow(IWindow* window) override;
};

}
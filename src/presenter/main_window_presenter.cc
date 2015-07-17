#include <presenter/main_window_presenter.h>

#include <view/interfaces/i_window.h>
#include <view/interfaces/i_main_window.h>

namespace erebus {

MainWindowPresenter::MainWindowPresenter() {
	mainWindow_=nullptr;
}

MainWindowPresenter::~MainWindowPresenter() {

}

void MainWindowPresenter::setWindow(IWindow* window) {
	mainWindow_=static_cast<IMainWindow*>(window);
}

IWindow* MainWindowPresenter::getWindow() {
	return mainWindow_;
}

}//namespace erbus
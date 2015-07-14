#include <presenter/main_window_presenter.h>

#include <view/interfaces/i_main_window.h>

namespace erebus {

MainWindowPresenter::MainWindowPresenter() {

}

MainWindowPresenter::~MainWindowPresenter() {

}

void MainWindowPresenter::setWindow(IWindow* window) {
	mainWindow_=static_cast<IMainWindow*>(window);
}

}//namespace erbus
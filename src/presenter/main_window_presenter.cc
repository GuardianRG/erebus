#include <presenter/main_window_presenter.h>

#include <assert.h>

#include <view/interfaces/i_window.h>
#include <view/interfaces/i_main_window.h>

namespace erebus {

MainWindowPresenter::MainWindowPresenter() {
	mainWindow_=nullptr;
}

MainWindowPresenter::~MainWindowPresenter() {

}

MainWindowPresenter::MainWindowPresenter( MainWindowPresenter&& obj): mainWindow_(obj.mainWindow_) {

}

MainWindowPresenter& MainWindowPresenter::operator=(MainWindowPresenter&& obj) {
	if(this != &obj) {
		mainWindow_=obj.mainWindow_;
	}
	return *this;
}

void MainWindowPresenter::setWindow(IWindow* window) {
	mainWindow_=dynamic_cast<IMainWindow*>(window);
	assert(mainWindow_!=0);
}


}//namespace erbus

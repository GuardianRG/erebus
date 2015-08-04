#include <presenter/main_window_presenter.h>

#include <view/interfaces/i_window.h>
#include <view/interfaces/i_main_window.h>

#include <view/view_preferences_saver.h>
#include <presenter/presenter_logger.h>

INIT_LOCATION;

namespace erebus {

MainWindowPresenter::MainWindowPresenter() {
	mainWindow_=nullptr;
}

MainWindowPresenter::~MainWindowPresenter() {

}

MainWindowPresenter::MainWindowPresenter( MainWindowPresenter&& obj):
	mainWindow_(obj.mainWindow_) {

}

MainWindowPresenter& MainWindowPresenter::operator=(MainWindowPresenter&& obj) {
	if(this != &obj) {
		mainWindow_=obj.mainWindow_;
	}
	return *this;
}

void MainWindowPresenter::setWindow(IWindow* window) {
	mainWindow_=dynamic_cast<IMainWindow*>(window);
	LOG_ASSERT(presenter_l::get(),mainWindow_!=0);
}

void MainWindowPresenter::on_menu_view_save_click() {

}

void MainWindowPresenter::on_menu_view_show_tabs_click() {

}


}//namespace erbus

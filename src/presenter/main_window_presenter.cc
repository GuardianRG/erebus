#include <main_window_presenter.h>

#include <stdexcept>

#include <i_window.h>
#include <i_main_window.h>
#include <i_gui_manager.h>

#include <presenter_logger.h>
#include <view_preferences_saver.h>

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

void MainWindowPresenter::setWindow(IWindow& window) {
	try {
		mainWindow_=&(dynamic_cast<IMainWindow&>(window));
	} catch(const std::bad_cast& e) {
		LOG_PRESENTER(error)<<"Cast failed.";
		throw;
	}
}

void MainWindowPresenter::on_menu_view_save_preferences_click() {
	LOG_ASSERT_PRESENTER(mainWindow_!=nullptr);
	
	ViewPreferencesSaver::saveAsCustomViewPreferences(mainWindow_->getGUIManager().getViewPreferences());
}

void MainWindowPresenter::on_menu_view_new_window_click() {
	LOG_ASSERT_PRESENTER(mainWindow_!=nullptr);

	mainWindow_->getGUIManager().createNewViewWindow();
}

}//namespace erbus

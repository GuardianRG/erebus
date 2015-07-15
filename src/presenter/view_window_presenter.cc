#include <presenter/view_window_presenter.h>

#include <view/interfaces/i_view_window.h>

namespace erebus {

ViewWindowPresenter::ViewWindowPresenter() {

}

ViewWindowPresenter::~ViewWindowPresenter() {

}

void ViewWindowPresenter::setWindow(IWindow* window) {
	mainWindow_=static_cast<IViewWindow*>(window);
}


}//namespace erebus
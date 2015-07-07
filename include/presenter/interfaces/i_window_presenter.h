#pragma once

#include <presenter/interfaces/i_presenter.h>
#include <view/interfaces/i_window.h>

namespace erebus {
	class IWindowPresenter:public IPresenter {
	public:
		virtual ~IWindowPresenter() {}
		
		virtual void setWindow(IWindow* window) =0;
	};
}
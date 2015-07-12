#pragma once

#include <presenter/interfaces/i_empty_view_presenter.h>
#include <presenter/view_presenter.h>

namespace erebus {
class EmptyViewPresenter :public ViewPresenter {
  public:
	EmptyViewPresenter();
	~EmptyViewPresenter();
	
};
}
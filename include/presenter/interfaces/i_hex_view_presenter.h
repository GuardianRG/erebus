#pragma once

#include <presenter/interfaces/i_view_presenter.h>

namespace erebus {
class IHexView;

class IHexViewPresenter:public IViewPresenter {
  public:
	~IHexViewPresenter() {}

	virtual void setView(IHexView* view)=0;

	virtual IHexView* getView() const=0;
};

}//namespace erebus

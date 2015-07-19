#pragma once

#include <presenter/interfaces/i_view_presenter.h>

namespace erebus {
class IEmptyView;
/**
 * This class is the interfaces for a empty view presenter.
 */
class IEmptyViewPresenter:public IViewPresenter {


  public:
	/**
	 * Destructor.
	 */
	virtual ~IEmptyViewPresenter() {}

	virtual void setView(IEmptyView* view)=0;

	virtual IEmptyView* getView()=0;
};

}//namespace erbus

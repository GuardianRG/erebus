#pragma once

namespace erebus {

class IView;

}

namespace erebus {

/**
 * This class is the base interface for a view presenter.
 */
class IViewPresenter {
  public:
	/**
	 * Destructor.
	 */
	virtual ~IViewPresenter() {}

	/**
	 * Sets the view of the presenter.
	 *
	 * @param click the view of the presenter.
	 */
	virtual void setView(IView& view)=0;
};

}//namespace erbus

#pragma once

#include <presenter/interfaces/i_empty_view_presenter.h>

namespace erebus {
	class IView;
	class IEmptyView;
}

namespace erebus {

/**
 * This class is a concrete empty view presenter.
 */
class EmptyViewPresenter :public IEmptyViewPresenter {
	IEmptyView* view_;
	
  public:
	/**
	 * Constructor.
	 */
	EmptyViewPresenter();

	/**
	 * Copy constructor.
	 *
	 * Cant be copied.
	 */
	EmptyViewPresenter(const EmptyViewPresenter &obj)=delete;

	/**
	 * Move Constructor.
	 */
	EmptyViewPresenter( EmptyViewPresenter&& );

	/**
	 * Copy assignment operator.
	 *
	 * Cant be copied.
	 */
	EmptyViewPresenter& operator=(const EmptyViewPresenter&)=delete;

	/**
	 * Move assignment operator.
	 */
	EmptyViewPresenter& operator=(EmptyViewPresenter&&);

	/**
	 * Destructor.
	 */
	virtual ~EmptyViewPresenter();


	/**
	 * See IEmptyViewPresenter::setView.
	 */
	virtual void setView(IView& view) override;

};

}//namespace erbus

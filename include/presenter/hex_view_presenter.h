#pragma once

#include <presenter/interfaces/i_hex_view_presenter.h>

namespace erebus {
class IHexView;
class IView;
}

namespace erebus {

/**
 * This class is a concrete HexView presenter
 */
class HexViewPresenter:public IHexViewPresenter {
	IHexView*	view_;

  public:
	/**
	 * Constructor.
	 */
	HexViewPresenter();

	/**
	 * Copy constructor.
	 *
	 * Cant be copied.
	 */
	HexViewPresenter(const HexViewPresenter &obj)=delete;

	/**
	 * Move Constructor.
	 */
	HexViewPresenter( HexViewPresenter&& );

	/**
	 * Copy assignment operator.
	 *
	 * Cant be copied.
	 */
	HexViewPresenter& operator=(const HexViewPresenter&)=delete;

	/**
	 * Move assignment operator.
	 */
	HexViewPresenter& operator=(HexViewPresenter&&);

	/**
	 * Destructor.
	 */
	virtual ~HexViewPresenter();


	/**
	 * See IHexViewPresenter::setView.
	 */
	virtual void setView(IView& view)override;

};

}//namespace erebus

#pragma once

#include <model.h>

namespace erebus {
	
	/**
	 * This class is the base interface for every presenter.
	 */
class IPresenter {
  protected:
	  /**
	   * Model to operate on.
	   */
	Model*	model_;
  public:
	  /**
	   * Destructor.
	   */
	virtual ~IPresenter() {}
	
	/**
	 * Sets the model to operate on.
	 * 
	 * @param m model to operate on
	 */
	void setModel(Model* m) {
		model_=m;
	}
};
}//namespace erbus
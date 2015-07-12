#pragma once

#include <model.h>

namespace erebus {
class IPresenter {
  protected:
	Model*	model_;
  public:
	virtual ~IPresenter() {}

	void setModel(Model* m) {
		model_=m;
	}
};
}
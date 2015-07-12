#pragma once

#include <view/interfaces/i_view.h>

namespace erebus {

class IEmptyView : public IView {
  public:
	virtual ~IEmptyView() {}
};

}
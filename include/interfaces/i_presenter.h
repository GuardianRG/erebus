#pragma once

#include <interfaces/i_view.h>
#include <interfaces/i_model.h>

namespace erebus {

class IPresenter {
public:
	virtual ~IPresenter() {}
	virtual void setView(IView* view)=0;
	virtual void setModel(IModel* model)=0;
};
}
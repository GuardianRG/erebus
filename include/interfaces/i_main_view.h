#pragma once

#include "i_view.h"
#include <boost/function.hpp>

namespace erebus {

class IMainView: public IView {
public:
	virtual ~IMainView(){}
	virtual void registerFunctionQuit(boost::function<void()> func)=0;
};


}
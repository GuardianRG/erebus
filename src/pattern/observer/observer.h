#pragma once

#include "action.h"

namespace observer {

class Observer {
public:
	virtual void receiveMessage(Action* action)=0;
};

}
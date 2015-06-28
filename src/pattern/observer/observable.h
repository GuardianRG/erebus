#pragma once

#include <memory>
#include <vector>

#include "observer.h"
#include "action.h"

namespace observer {

class Observable {
	std::vector<Observer*>	observer_;
	
public:
	void registerObserver(Observer* observer);
	
	void notifyAll(Action action) const;
};

}
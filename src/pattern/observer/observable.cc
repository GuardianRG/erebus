#include "observable.h"
#include "observer.h"
#include "action.h"

namespace observer {
	void Observable::registerObserver(Observer* observer) {
		observer_.push_back(observer);
	}
	
	void Observable::notifyAll(Action action) const{
		for(auto& obs:observer_) {
			obs->receiveMessage(&action);
		}
	}
}
#include "action.h"

namespace observer {
	Action::Action(int actionCode):actionCode_(actionCode) {
		
	}
	
	int Action::getAction() const {
		return actionCode_;
	}
	
}
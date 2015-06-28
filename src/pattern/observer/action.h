#pragma once

namespace observer {

class Action {
private:
	int actionCode_;
public:
	Action(int actionCode);
	~Action();
	
	int getAction() const;
};

}
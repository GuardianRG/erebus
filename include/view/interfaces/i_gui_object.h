#pragma once

#include <string>

namespace erebus {
class IGUIObject {
public:
	~IGUIObject() {}
	
	virtual std::string classname()=0;
	virtual std::size_t getID()=0;
};
	
	
}//namespace erebus
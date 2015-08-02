#pragma once

#include <string>

namespace erebus {

enum class ErrorLevel {
	INFO,
	ERROR
};


class IGUIManager {
  public:
	~IGUIManager() {}

	virtual void showMessageDialog(std::string primaryText,std::string secondaryText,
	                               ErrorLevel errorLevel)=0;

	virtual void runGUI()=0;
};

}//namespace erebus
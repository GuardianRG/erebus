#pragma once

#include <string>

namespace erebus {
	
	class ViewPreference {
		std::string value_;
		
	protected:
		virtual bool isValueValid(const std::string& value);
	public:
		ViewPreference(const std::string& value);
		~ViewPreference();
		
		virtual std::string getKey()=0;
		
		virtual void setValue(const std::string& value);
		
		virtual std::string getValueString();
		
		virtual bool getValueBool();
		
		virtual std::string getDefaultValue()=0;
	};

}//namespace erebus
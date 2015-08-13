#pragma once

#include <string>

#include <boolean_view_preference.h>

namespace erebus {
	
	class AlwaysShowTabsPref:public BooleanViewPreference {
		static const bool DEFAULT_VALUE;
	public:
		static const std::string KEY;
		
		AlwaysShowTabsPref(const std::string& value);
		AlwaysShowTabsPref(bool value);
		AlwaysShowTabsPref();
		~AlwaysShowTabsPref();
		
		std::string getKey()override;
		
		std::string getDefaultValue()override;
	};

}//namespace erebus
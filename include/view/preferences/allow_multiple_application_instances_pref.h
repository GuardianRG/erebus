#pragma once

#include <string>

#include <boolean_view_preference.h>

namespace erebus {
	
	class AllowMultipleApplicationInstancesPref:public BooleanViewPreference {
		static const bool DEFAULT_VALUE;
	public:
		static const std::string KEY;
		
		AllowMultipleApplicationInstancesPref(const std::string& value);
		AllowMultipleApplicationInstancesPref(bool value);
		AllowMultipleApplicationInstancesPref();
		~AllowMultipleApplicationInstancesPref();
		
		std::string getKey()override;
		
		std::string getDefaultValue()override;
	};

}//namespace erebus
#pragma once

#include <string>

#include <boolean_view_preference.h>

namespace erebus {

	class CloseViewWindowWhenEmptyPref:public BooleanViewPreference {
		static const bool DEFAULT_VALUE;
	public:
		static const std::string KEY;
		
		CloseViewWindowWhenEmptyPref(const std::string& value);
		CloseViewWindowWhenEmptyPref(bool value);
		CloseViewWindowWhenEmptyPref();
		~CloseViewWindowWhenEmptyPref();
		
		std::string getKey()override;
		
		std::string getDefaultValue()override;

};

}//namespace erebus
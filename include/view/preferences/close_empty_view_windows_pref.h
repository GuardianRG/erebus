#pragma once

#include <string>

#include <boolean_view_preference.h>

namespace erebus {

	class CloseEmptyViewWindowsPref:public BooleanViewPreference {
		static const bool DEFAULT_VALUE;
	public:
		static const std::string KEY;
		
		CloseEmptyViewWindowsPref(const std::string& value);
		CloseEmptyViewWindowsPref(bool value);
		CloseEmptyViewWindowsPref();
		~CloseEmptyViewWindowsPref();
		
		std::string getKey()override;
		
		std::string getDefaultValue()override;

};

}//namespace erebus
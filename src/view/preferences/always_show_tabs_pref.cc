#include <always_show_tabs_pref.h>

#include <string>

#include <boolean_view_preference.h>
#include <logger.h>

INIT_LOCATION;

namespace erebus {
	
	const std::string AlwaysShowTabsPref::KEY="always_show_tabs";
	
	const bool AlwaysShowTabsPref::DEFAULT_VALUE=true;
	
	AlwaysShowTabsPref::AlwaysShowTabsPref(const std::string& value):BooleanViewPreference(value) {
		
	}
	
	AlwaysShowTabsPref::AlwaysShowTabsPref(bool value):BooleanViewPreference(value) {
		
	}
	
	AlwaysShowTabsPref::AlwaysShowTabsPref():BooleanViewPreference(getDefaultValue()) {
		
	}
	
	AlwaysShowTabsPref::~AlwaysShowTabsPref() {
		
	}
	
	std::string AlwaysShowTabsPref::getKey() {
		return KEY;
	}
	
	std::string AlwaysShowTabsPref::getDefaultValue() {
		return BooleanViewPreference::boolToStr(DEFAULT_VALUE);
	}

}//namespace erebus
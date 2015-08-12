#include <allow_multiple_application_instances_pref.h>

#include <string>

#include <boolean_view_preference.h>
#include <logger.h>

INIT_LOCATION;

namespace erebus {
	
	const std::string AllowMultipleApplicationInstancesPref::KEY="allow_multiple_application_instances";
	
	const bool AllowMultipleApplicationInstancesPref::DEFAULT_VALUE=true;
	
	AllowMultipleApplicationInstancesPref::AllowMultipleApplicationInstancesPref(const std::string& value):BooleanViewPreference(value) {
		
	}
	
	AllowMultipleApplicationInstancesPref::AllowMultipleApplicationInstancesPref(bool value):BooleanViewPreference(value) {
		
	}
	
	AllowMultipleApplicationInstancesPref::AllowMultipleApplicationInstancesPref():BooleanViewPreference(getDefaultValue()) {
		
	}
	
	AllowMultipleApplicationInstancesPref::~AllowMultipleApplicationInstancesPref() {
		
	}
	
	std::string AllowMultipleApplicationInstancesPref::getKey() {
		return KEY;
	}
	
	std::string AllowMultipleApplicationInstancesPref::getDefaultValue() {
		return BooleanViewPreference::boolToStr(DEFAULT_VALUE);
	}

}//namespace erebus
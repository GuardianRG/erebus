#include <allow_multiple_application_instances_pref.h>

#include <string>

#include <boolean_view_preference.h>

namespace erebus {
	
	const std::string AllowMultipleApplicationInstancesPref::KEY="allowMultipleApplicationInstances";
	
	const bool AllowMultipleApplicationInstancesPref::DEFAULT_VALUE=false;
	
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
#include <close_view_window_when_empty_pref.h>

#include <string>

#include <boolean_view_preference.h>

namespace erebus {
	const std::string CloseViewWindowWhenEmptyPref::KEY="close_view_window_when_empty";
	
	const bool CloseViewWindowWhenEmptyPref::DEFAULT_VALUE=true;
	
	CloseViewWindowWhenEmptyPref::CloseViewWindowWhenEmptyPref(const std::string& value):BooleanViewPreference(value) {
		
	}
	
	CloseViewWindowWhenEmptyPref::CloseViewWindowWhenEmptyPref(bool value):BooleanViewPreference(value) {
		
	}
	
	CloseViewWindowWhenEmptyPref::CloseViewWindowWhenEmptyPref():BooleanViewPreference(getDefaultValue()) {
		
	}
	
	CloseViewWindowWhenEmptyPref::~CloseViewWindowWhenEmptyPref() {
		
	}
	
	std::string CloseViewWindowWhenEmptyPref::getKey() {
		return KEY;
	}
	
	std::string CloseViewWindowWhenEmptyPref::getDefaultValue() {
		return BooleanViewPreference::boolToStr(DEFAULT_VALUE);
	}
}//namespace erebus
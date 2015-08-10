#include <boolean_view_preference.h>

#include <string>
#include <stdexcept>

#include <view_preference.h>

namespace erebus {
	
	const std::string BooleanViewPreference::TRUE="true";
	const std::string BooleanViewPreference::FALSE="false";
	
	BooleanViewPreference::BooleanViewPreference(const std::string& value):ViewPreference(value) {
		
	}
	
	BooleanViewPreference::BooleanViewPreference(bool value):ViewPreference(boolToStr(value)) {
		
	}
	
	BooleanViewPreference::~BooleanViewPreference() {
		
	}
	
	bool BooleanViewPreference::strToBool(const std::string& value) {
		return value=="true";
	}
	
	bool BooleanViewPreference::isValueValid(const std::string& value) {
		return (value=="false"||value=="true")&&ViewPreference::isValueValid(value);
	}
	
	std::string BooleanViewPreference::boolToStr(bool value) {
		return value?"true":"false";
	}
	
	bool BooleanViewPreference::getValueBool() {
		return strToBool(getValueString());
	}
	
	void BooleanViewPreference::setValue(bool value) {
		setValue(boolToStr(value));
	}
	
}//namespace erebus
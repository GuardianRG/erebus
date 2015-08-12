#include <boolean_view_preference.h>

#include <string>
#include <stdexcept>

#include <view_preference.h>

namespace erebus {
	
	const std::string BooleanViewPreference::STRUE="true";
	const std::string BooleanViewPreference::SFALSE="false";
	
	BooleanViewPreference::BooleanViewPreference(const std::string& value):ViewPreference(value) {
		
	}
	
	BooleanViewPreference::BooleanViewPreference(bool value):ViewPreference(boolToStr(value)) {
		
	}
	
	BooleanViewPreference::~BooleanViewPreference() {
		
	}
	
	bool BooleanViewPreference::strToBool(const std::string& value) {
		return value==STRUE;
	}
	
	bool BooleanViewPreference::isValueValid(const std::string& value) {
		return (value==SFALSE||value==STRUE)&&ViewPreference::isValueValid(value);
	}
	
	std::string BooleanViewPreference::boolToStr(bool value) {
		return value?STRUE:SFALSE;
	}
	
	bool BooleanViewPreference::getValueBool() {
		return strToBool(getValue());
	}
	
	void BooleanViewPreference::setValue(bool value) {
		setValue(boolToStr(value));
	}
	
}//namespace erebus
#include <view_preference.h>

#include <string>
#include <stdexcept>

#include <logger.h>
#include <view_preference_factory.h>

INIT_LOCATION;

namespace erebus {
	
	ViewPreference::ViewPreference(const std::string& value) {
		setValue(value);
	}
	
	ViewPreference::~ViewPreference() {
		
	}
	
	bool ViewPreference::isValueValid(const std::string& value) {
		return value!=ViewPreferenceFactory::INVALID_KEY;
	}
	
	std::string ViewPreference::getValueString() {
		return value_;
	}
	
	bool ViewPreference::getValueBool() {
		LOG_ASSERT_MAIN(false);
		return true;
	}
	
	void ViewPreference::setValue(const std::string& value) {
		if(!isValueValid(value)) {
			throw std::invalid_argument(std::string("Invalid value '")+value+"' for view preference '"+getKey()+"'");
		}
		value_=value;
	}

}//namespace erebus
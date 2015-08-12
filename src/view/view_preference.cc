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
		return value!=ViewPreferenceFactory::INVALID_VALUE;
	}
	
	std::string ViewPreference::getValue() {
		return value_;
	}
	
	void ViewPreference::setValue(const std::string& value) {
		if(!isValueValid(value)) {
			throw std::invalid_argument(std::string("Invalid value '")+value+"' for view preference '"+getKey()+"'");
		}
		value_=value;
	}

}//namespace erebus

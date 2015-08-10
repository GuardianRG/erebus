#include <view_preferences_manager.h>

#include <memory>
#include <string>
#include <algorithm>

#include <no_such_element.h>
#include <logger.h>
#include <view_preferences_loader.h>
#include <view_preference.h>
#include <view_preference_factory.h>
#include <boolean_view_preference.h>


namespace erebus {
	
	const std::string ViewPreferencesManager::CUSTOM_VIEW_PREFERENCES_FILE="view_preferences.pref";
	const std::string ViewPreferencesManager::DEFAULT_VIEW_PREFERENCES_FILE="resources/default_view_preferences.pref";

ViewPreferencesManager::ViewPreferencesManager() {
	
}

ViewPreferencesManager::~ViewPreferencesManager() {

}


std::string ViewPreferencesManager::getPreference(const std::string& key) {
	if(!ViewPreferenceFactory::isKeyValid(key)) {
		throw no_such_element(std::string("'")+key+"' is not a valid key");
	}
	
	auto preference=preferences_.find(key);
	
	if(preference==preferences_.end()) {
		throw no_such_element(std::string("'")+key+"' was not found");
	}
	
	return preference->second->getValueString();
}

void ViewPreferencesManager::setPreference(const std::string& key,const std::string& value) {
	if(!ViewPreferenceFactory::isKeyValid(key)) {
		throw no_such_element(std::string("'")+key+"' is not a valid key");
	}
	
	auto preference=preferences_.find(key);
	
	if(preference==preferences_.end()) {
		preferences_.insert(std::make_pair<std::string,std::unique_ptr<ViewPreference>>(std::string(key),ViewPreferenceFactory::createViewPreference(key,value)));
	}
	else {
		preference->second->setValue(key);
	}
}

bool ViewPreferencesManager::getBooleanPreference(const std::string& key) {
	if(!ViewPreferenceFactory::isKeyValid(key)) {
		throw no_such_element(std::string("'")+key+"' is not a valid key");
	}
	
	auto preference=preferences_.find(key);
	
	if(preference==preferences_.end()) {
		throw no_such_element(std::string("'")+key+"' was not found");
	}
	
	return preference->second->getValueBool();
}

void ViewPreferencesManager::setBooleanPreference(const std::string&key, bool value) {
	setPreference(key,BooleanViewPreference::boolToStr(value));
}

}//namespace erebus

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

INIT_LOCATION;

namespace erebus {

const std::string ViewPreferencesManager::CUSTOM_VIEW_PREFERENCES_FILE="view_preferences.pref";
const std::string ViewPreferencesManager::DEFAULT_VIEW_PREFERENCES_FILE=
    "resources/default_view_preferences.pref";

ViewPreferencesManager::ViewPreferencesManager() {

}

ViewPreferencesManager::~ViewPreferencesManager() {

}


std::string ViewPreferencesManager::getPreference(const std::string& key) {
	return getPreferencePr(key)->getValue();
}

ViewPreference* ViewPreferencesManager::getPreferencePr(const std::string& key) {
	if(!ViewPreferenceFactory::isKeyValid(key)) {
		throw no_such_element(std::string("'")+key+"' is not a valid key");
	}

	auto preference=preferences_.find(key);

	if(preference==preferences_.end()) {
		return insertDefaultViewPreference(key);
	}

	return preference->second.get();
}

void ViewPreferencesManager::setPreference(const std::string& key,const std::string& value) {
	getPreferencePr(key)->setValue(value);
}

ViewPreference* ViewPreferencesManager::insertDefaultViewPreference(const std::string& key) {
	if(!ViewPreferenceFactory::isKeyValid(key)) {
		throw no_such_element(std::string("'")+key+"' is not a valid key");
	}

	auto preference=preferences_.find(key);

	if(preference==preferences_.end()) {
		auto pref=ViewPreferenceFactory::createViewPreference(key);
		auto ptr=pref.get();
		preferences_.insert(std::make_pair<std::string,std::unique_ptr<ViewPreference>>(std::string(key),
		                    std::move(pref)));
		return ptr;
	}

	return preference->second.get();
}


bool ViewPreferencesManager::getPreferenceBool(const std::string& key) {
	auto pref=dynamic_cast<BooleanViewPreference*>(getPreferencePr(key));

	if(pref==0) {
		throw no_such_element(std::string("'")+key+"' is not a bool view preference");
	}

	return pref->getValueBool();
}

void ViewPreferencesManager::setPreferenceBool(const std::string&key, bool value) {
	setPreference(key,BooleanViewPreference::boolToStr(value));
}

}//namespace erebus

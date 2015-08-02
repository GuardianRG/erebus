#include <view/view_preferences.h>

#include <memory>
#include <string>
#include <assert.h>

#include <logger.h>
#include <view/view_preferences_loader.h>

namespace erebus {

std::string const ViewPreferences::ALWAYS_SHOW_TABS="always_show_tabs";


std::string const ViewPreferences::VIEW_PREFERENCE_FILE="view_preferences.pref";

std::string const ViewPreferences::DEFAULT_VIEW_PREFERENCE_FILE=
    "resources/default_view_preferences.pref";

ViewPreferences::ViewPreferences() {
	alwaysShowTabs_=true;
}

ViewPreferences::~ViewPreferences() {

}

bool ViewPreferences::getAlwaysShowTabs() const {
	return alwaysShowTabs_;
}

void ViewPreferences::setAlwaysShowTabs(bool show) {
	alwaysShowTabs_=show;
}


}//namespace erebus

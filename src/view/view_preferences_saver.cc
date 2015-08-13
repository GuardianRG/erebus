#include <view/view_preferences_saver.h>

#include <iostream>
#include <fstream>
#include <string>

#include <logger.h>
#include <file_system.h>
#include <types.h>
#include <view_preferences_manager.h>

INIT_LOCATION;

namespace erebus {
ViewPreferencesSaver::ViewPreferencesSaver(const std::string& file,
        ViewPreferencesManager& manager):file_(file),manager_(manager) {
	if(!doesFileExist(file)) {
		createFile(file);
		LOG_MAIN(notification)<<"Created view preferences file '"<<file<<"'";
	}
	preferenceFile_= std::make_unique<std::ofstream>(file);
}



ViewPreferencesSaver::~ViewPreferencesSaver() {
	preferenceFile_->close();
}

void ViewPreferencesSaver::saveAsCustomViewPreferences(ViewPreferencesManager& manager) {
	ViewPreferencesSaver saver(ViewPreferencesManager::CUSTOM_VIEW_PREFERENCES_FILE,manager);
	saver.saveViewPreferences();
}

void ViewPreferencesSaver::saveViewPreferences() {
	LOG_MAIN(notification)<<"Saving view preferences to file '"<<file_<<"'";

	auto it=manager_.begin();
	while(it!=manager_.end()) {
		writeToFile(it->second.get()->getKey(),it->second.get()->getValue());
		it++;
	}
}

void ViewPreferencesSaver::writeToFile(std::string pref,std::string val) {
	*preferenceFile_<<pref<<"="<<val<<std::endl;
}

}//namespace erebus

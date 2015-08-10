#include <view/view_preferences_loader.h>

#include <sstream>
#include <typeinfo>
#include <string>
#include <fstream>
#include <vector>

#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/trim.hpp>

#include <view_preferences_manager.h>
#include <logger.h>
#include <file_system.h>
#include <types.h>

INIT_LOCATION;

namespace erebus {
	
ViewPreferencesLoader::ViewPreferencesLoader(const std::string& file):file_(file) {

}
ViewPreferencesLoader::~ViewPreferencesLoader() {

}

std::unique_ptr<ViewPreferencesManager> ViewPreferencesLoader::loadCustomViewPreferences() {
	/*LOG_MAIN(notification)<<"Loading custom view preferences";

	if(!doesFileExist(ViewPreferences::CUSTOM_VIEW_PREFERENCES_FILE)) {
		LOG_MAIN(warning)<<"Custom view preferences file does not exist";
		return;
	}

	ViewPreferencesLoader loader(ViewPreferences::CUSTOM_VIEW_PREFERENCE_FILE);
	*/
	return nullptr;//std::move(loader.loadPreferences());
}

std::unique_ptr<ViewPreferencesManager> ViewPreferencesLoader::loadDefaultViewPreferences() {
	/*LOG_MAIN(notification)<<"Loading default view preferences";

	if(!doesFileExist(ViewPreferences::DEFAULT_VIEW_PREFERENCES_FILE)) {
		LOG_MAIN(warning)<<"Default view preferences file does not exist";
		return;
	}
	
	ViewPreferencesLoader loader(ViewPreferences::DEFAULT_VIEW_PREFERENCE_FILE);
*/
	return nullptr;//std::move(loader.loadPreferences());
}

std::unique_ptr<ViewPreferencesManager> ViewPreferencesLoader::loadPreferences(const std::string& file) {
	auto preferences=std::make_unique<ViewPreferencesManager>();

	/*std::ifstream infile(ViewPreferences::DEFAULT_VIEW_PREFERENCE_FILE);
	
	std::string line=="";
	bool faultyFile=false;
	while (std::getline(infile, line)) {
		if(line=="") {
			continue;
		}
		
		if(boost::starts_with(line, "#")) {
			continue;
		}

		std::vector<std::string> strs;
		boost::split(strs,line,boost::is_any_of("="));
		if(strs.size()!=2) {
			BOOST_LOG_SEV(main_l::get(),warning)<<LOCATION
			                                    <<"Uncorrect preference line '"
			                                    <<line<<"' in '"
			                                    <<file<<"'";
			continue;
		}

		boost::trim(strs[0]);
		boost::trim(strs[1]);
		boost::trim_if(strs[0],boost::is_any_of("\t"));
		boost::trim_if(strs[1],boost::is_any_of("\t"));

		if(!preferences.setPreference<std::string>(strs[0],strs[1])) {
			LOG_MAIN(warning)<<"Faulty key,value pair ("<<strs[0]<<","<<strs[1]<<")";
			faultyFile=true;
		}
	}
	
	if(faultyFile) {
		LOG_MAIN(notification)<<"Repairing preferences file '"<<file<<"'";
	}*/
	
	return preferences;
}

}//namespace erebus

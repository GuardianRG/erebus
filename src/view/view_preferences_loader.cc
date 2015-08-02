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

#include <view/view_preferences.h>
#include <logger.h>
#include <file_system.h>
#include <types.h>

INIT_LOCATION;

namespace erebus {
ViewPreferencesLoader::ViewPreferencesLoader() {

}
ViewPreferencesLoader::~ViewPreferencesLoader() {

}

void ViewPreferencesLoader::loadViewPreferences() {
	BOOST_LOG_SEV(main_l::get(),normal)<<LOCATION<<"Loading view preferences";

	if(!doesFileExist(ViewPreferences::VIEW_PREFERENCE_FILE)) {
		BOOST_LOG_SEV(main_l::get(),warning)
		        <<LOCATION<<"View preference file does not exist";
		return;
	}

	loadPreferences(ViewPreferences::VIEW_PREFERENCE_FILE);
}

void ViewPreferencesLoader::loadDefaultViewPreferences() {
	BOOST_LOG_SEV(main_l::get(),
	              normal)<<LOCATION<<"Loading default view preferences";

	if(!doesFileExist(ViewPreferences::DEFAULT_VIEW_PREFERENCE_FILE)) {
		BOOST_LOG_SEV(main_l::get(),warning)
		        <<LOCATION<<"Default view preference file does not exist";
		return;
	}

	loadPreferences(ViewPreferences::DEFAULT_VIEW_PREFERENCE_FILE);
}

void ViewPreferencesLoader::loadPreferences(const std::string& file) {
	/*auto& viewPref=ViewPreferences::getInstance();

	std::ifstream infile(ViewPreferences::DEFAULT_VIEW_PREFERENCE_FILE);
	std::string line;
	while (std::getline(infile, line)) {
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

		try {
			if(strs[0]==ViewPreferences::ALWAYS_SHOW_TABS) {
				viewPref.setAlwaysShowTabs(BoolStr::toBool(strs[1]));
			} else {
				BOOST_LOG_SEV(main_l::get(),warning)<<LOCATION
				                                    <<"Unknown preference '"
				                                    <<strs[0]<<"' in '"
				                                    <<file<<"'";
			}
		} catch(std::bad_cast& e) {
			BOOST_LOG_SEV(main_l::get(),warning)<<LOCATION
			                                    <<"Unknown value '"
			                                    <<strs[1]<<"' in '"
			                                    <<file<<"'";
		}
	}*/
}

}//namespace erebus

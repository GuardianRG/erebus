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
	
ViewPreferencesLoader::ViewPreferencesLoader(const std::string& file):file_(file),fileStream_(file) {

}
ViewPreferencesLoader::~ViewPreferencesLoader() {

}

std::unique_ptr<ViewPreferencesManager> ViewPreferencesLoader::loadCustomViewPreferences(std::unique_ptr<ViewPreferencesManager> manager) {
	LOG_MAIN(notification)<<"Loading custom view preferences";

	if(!doesFileExist(ViewPreferencesManager::CUSTOM_VIEW_PREFERENCES_FILE)) {
		LOG_MAIN(warning)<<"Custom view preferences file does not exist";
		return std::make_unique<ViewPreferencesManager>();
	}

	ViewPreferencesLoader loader(ViewPreferencesManager::CUSTOM_VIEW_PREFERENCES_FILE);
	
	return std::move(loader.loadPreferences(std::move(manager)));
}

std::unique_ptr<ViewPreferencesManager> ViewPreferencesLoader::loadDefaultViewPreferences(std::unique_ptr<ViewPreferencesManager> manager) {
	LOG_MAIN(notification)<<"Loading default view preferences";
	
	if(!doesFileExist(ViewPreferencesManager::DEFAULT_VIEW_PREFERENCES_FILE)) {
		LOG_MAIN(warning)<<"Default view preferences file does not exist";
		return std::make_unique<ViewPreferencesManager>();
	}
	
	ViewPreferencesLoader loader(ViewPreferencesManager::DEFAULT_VIEW_PREFERENCES_FILE);
	
	return std::move(loader.loadPreferences(std::move(manager)));
}

std::unique_ptr<ViewPreferencesManager> ViewPreferencesLoader::loadPreferences(std::unique_ptr<ViewPreferencesManager> manager) {
	fileStream_.clear();                 // clear fail and eof bits
	fileStream_.seekg(0, std::ios::beg); 
	
	std::string line("");
	while (std::getline(fileStream_, line)) {
		if(line=="") {
			continue;
		}
		
		if(boost::starts_with(line, "#")) {
			continue;
		}

		std::vector<std::string> strs;
		boost::split(strs,line,boost::is_any_of("="));
		if(strs.size()!=2) {
			LOG_MAIN(warning)<<LOCATION<<"Incorrect preference line '"
			                                    <<line<<"' in '"
			                                    <<file_<<"'";
			continue;
		}

		boost::trim(strs[0]);
		boost::trim(strs[1]);
		boost::trim_if(strs[0],boost::is_any_of("\t"));
		boost::trim_if(strs[1],boost::is_any_of("\t"));

		try {
			manager->setPreference(strs[0],strs[1]);
			LOG_MAIN(normal)<<"Loading view preference ("<<strs[0]<<"|"<<strs[1]<<")";
		}
		catch(const std::invalid_argument&e){
			LOG_MAIN(warning)<<"Wrong value '"<<strs[1]<<"' for key '"<<strs[0]<<"'";
		}
		catch(const no_such_element& e) {
			
			LOG_MAIN(warning)<<"Unknown key '"<<strs[0]<<"'";
		}
	}
	
	return std::move(manager);
}

}//namespace erebus

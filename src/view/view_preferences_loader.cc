#include <view/view_preferences_loader.h>

#include <sstream>
#include <typeinfo>
#include <string>
#include <memory>
#include <fstream>
#include <vector>

#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/trim.hpp>

#include <view_preferences_manager.h>
#include <logger.h>
#include <file_system.h>
#include <file_not_found.h>
#include <types.h>

INIT_LOCATION;

namespace erebus {
	
ViewPreferencesLoader::ViewPreferencesLoader(const std::string& file):file_(file) {
	if(!doesFileExist(file)) {
		throw file_not_found(std::string(file)+" does not exist");
	}
	fileStream_=std::make_unique<std::ifstream>(file);
}
ViewPreferencesLoader::~ViewPreferencesLoader() {
	fileStream_->close();
}

std::unique_ptr<ViewPreferencesManager> ViewPreferencesLoader::loadCustomViewPreferences(std::unique_ptr<ViewPreferencesManager> manager) {
	LOG_MAIN(notification)<<"Loading custom view preferences";
	
	std::unique_ptr<ViewPreferencesLoader> loader;
	try {
		loader=std::make_unique<ViewPreferencesLoader>(ViewPreferencesManager::CUSTOM_VIEW_PREFERENCES_FILE);
	}
	catch(const file_not_found& e) {
		LOG_MAIN(warning)<<"Custom view preferences file does not exist";
		return std::move(manager);
	}
	
	return std::move(loader->loadPreferences(std::move(manager)));
}

std::unique_ptr<ViewPreferencesManager> ViewPreferencesLoader::loadDefaultViewPreferences(std::unique_ptr<ViewPreferencesManager> manager) {
	LOG_MAIN(notification)<<"Loading default view preferences";
	
	std::unique_ptr<ViewPreferencesLoader> loader;
	try {
		loader=std::make_unique<ViewPreferencesLoader>(ViewPreferencesManager::DEFAULT_VIEW_PREFERENCES_FILE);
	}
	catch(const file_not_found& e) {
		LOG_MAIN(warning)<<"Custom view preferences file does not exist";
		return std::move(manager);
	}
	
	return std::move(loader->loadPreferences(std::move(manager)));
}

std::unique_ptr<ViewPreferencesManager> ViewPreferencesLoader::loadPreferences(std::unique_ptr<ViewPreferencesManager> manager) {
	LOG_ASSERT_MAIN(manager.get()!=nullptr);
	
	fileStream_->clear();                 // clear fail and eof bits
	fileStream_->seekg(0, std::ios::beg); 
	
	std::string line;
	while (std::getline(*fileStream_.get(), line)) {
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

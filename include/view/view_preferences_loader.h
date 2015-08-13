#pragma once

#include <string>
#include <memory>
#include <fstream>

#include <view_preferences_manager.h>

namespace erebus {

class ViewPreferencesLoader {
	std::string file_;
	std::unique_ptr<std::ifstream> fileStream_;

  public:
	ViewPreferencesLoader(const std::string& file);
	~ViewPreferencesLoader();

	std::unique_ptr<ViewPreferencesManager> loadPreferences(std::unique_ptr<ViewPreferencesManager>
	        manager=std::make_unique<ViewPreferencesManager>());

	static std::unique_ptr<ViewPreferencesManager> loadCustomViewPreferences(
	    std::unique_ptr<ViewPreferencesManager> manager=std::make_unique<ViewPreferencesManager>());

	static std::unique_ptr<ViewPreferencesManager> loadDefaultViewPreferences(
	    std::unique_ptr<ViewPreferencesManager> manager=std::make_unique<ViewPreferencesManager>());
};

}//namespace erebus

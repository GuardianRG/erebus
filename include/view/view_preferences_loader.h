#pragma once

#include <string>
#include <memory>

#include <view_preferences_manager.h>

namespace erebus {

class ViewPreferencesLoader {
	std::string file_;
  public:
	ViewPreferencesLoader(const std::string& file);
	~ViewPreferencesLoader();
	
	std::unique_ptr<ViewPreferencesManager> loadPreferences(const std::string&);

	static std::unique_ptr<ViewPreferencesManager> loadCustomViewPreferences();

	static std::unique_ptr<ViewPreferencesManager> loadDefaultViewPreferences();
};

}//namespace erebus

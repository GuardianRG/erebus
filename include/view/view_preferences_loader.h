#pragma once

#include <string>

namespace erebus {

class ViewPreferencesLoader {
	void loadPreferences(const std::string& file);
  public:
	ViewPreferencesLoader();
	~ViewPreferencesLoader();

	void loadViewPreferences();

	void loadDefaultViewPreferences();
};

}//namespace erebus

#pragma once

#include <memory>
#include <string>

namespace erebus {
class ViewPreferences {

	bool			alwaysShowTabs_;

	
  public:
	static const std::string 	ALWAYS_SHOW_TABS;

	static const std::string 	VIEW_PREFERENCE_FILE;
	static const std::string 	DEFAULT_VIEW_PREFERENCE_FILE;
	ViewPreferences();
	~ViewPreferences();


	bool getAlwaysShowTabs()const;

	void setAlwaysShowTabs(bool show);
};
}//namespace erebus

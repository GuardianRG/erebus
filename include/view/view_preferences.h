#pragma once

#include <memory>
#include <string>

namespace erebus {
class ViewPreferences {

	static std::unique_ptr<ViewPreferences> instance_;

	bool			alwaysShowTabs_;

	ViewPreferences();
  public:
	static const std::string 	ALWAYS_SHOW_TABS;

	static const std::string 	VIEW_PREFERENCE_FILE;
	static const std::string 	DEFAULT_VIEW_PREFERENCE_FILE;

	~ViewPreferences();

	static ViewPreferences& getInstance();

	bool getAlwaysShowTabs()const;

	void setAlwaysShowTabs(bool show);
};
}//namespace erebus

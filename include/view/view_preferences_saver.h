#pragma once

#include <fstream>
#include <string>
#include <memory>

#include <view_preferences_manager.h>

namespace erebus {

class ViewPreferencesSaver {
	std::unique_ptr<std::ofstream>		preferenceFile_;
	std::string file_;
	ViewPreferencesManager& manager_;

	void writeToFile(std::string pref,std::string val);
  public:
	ViewPreferencesSaver(const std::string& file,ViewPreferencesManager& manager);

	/**
	 * Copy constructor.
	 *
	 * Cant be copied.
	 */
	ViewPreferencesSaver(const ViewPreferencesSaver &obj)=delete;

	/**
	 * Move Constructor.
	 */
	ViewPreferencesSaver( ViewPreferencesSaver&& )=delete;

	/**
	 * Copy assignment operator.
	 *
	 * Cant be copied.
	 */
	ViewPreferencesSaver& operator=(const ViewPreferencesSaver&)=delete;

	/**
	 * Move assignment operator.
	 */
	ViewPreferencesSaver& operator=(ViewPreferencesSaver&&)=delete;

	~ViewPreferencesSaver();

	void saveViewPreferences();

	static void saveAsCustomViewPreferences(ViewPreferencesManager& manager);
};

}//namespace erebus

#pragma once

#include <fstream>

namespace erebus {

class ViewPreferencesSaver {
	std::ofstream*		preferenceFile_;

	void writeToFile(std::string pref,std::string val);
  public:
	ViewPreferencesSaver();

	/**
	 * Copy constructor.
	 *
	 * Cant be copied.
	 */
	ViewPreferencesSaver(const ViewPreferencesSaver &obj)=delete;

	/**
	 * Move Constructor.
	 */
	ViewPreferencesSaver( ViewPreferencesSaver&& );

	/**
	 * Copy assignment operator.
	 *
	 * Cant be copied.
	 */
	ViewPreferencesSaver& operator=(const ViewPreferencesSaver&)=delete;

	/**
	 * Move assignment operator.
	 */
	ViewPreferencesSaver& operator=(ViewPreferencesSaver&&);

	~ViewPreferencesSaver();

	void saveViewPreferences();
};

}//namespace erebus

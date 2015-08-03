#pragma once

#include <string>

namespace erebus {

/**
 * This class holds the paths to the glade files for the windows.
 */
class Windows {
  public:
	/**
	 * Path to the main window file.
	 */
	static std::string 	MAIN_WINDOW;

	/**
	 * Path to the view window file.
	 */
	static std::string 	VIEW_WINDOW;
};

/**
 * This class holds the paths to the glade files for the views.
 */
class Views {
  public:
	/**
	 * Path to the empty view file.
	 */
	static std::string 	EMPTY_VIEW;

	/**
	 * Path to the hex view file.
	 */
	static std::string 	HEX_VIEW;
};


}//namespace erebus

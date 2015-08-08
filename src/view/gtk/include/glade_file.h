#pragma once

#include <string>

namespace erebus {

enum class ViewType;
enum class WindowType;

}

namespace erebus {

/**
 * This class holds the paths to the glade files for the different view and window types.
 */
class GladeFile {
	GladeFile();

  public:
	/**
	 * Destructor.
	 */
	~GladeFile();

	/**
	 * Returns the relative path to the glade file for the given ViewType.
	 *
	 * @return relative path to the glade file
	 */
	static std::string getFile(ViewType type);

	/**
	 * Returns the relative path to the glade file for the given WindowType.
	 *
	 * @return relative path to the glade file
	 */
	static std::string getFile(WindowType type);
};


}//namespace erebus

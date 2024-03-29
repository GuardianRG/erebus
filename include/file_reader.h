#pragma once

#include <string>

#include <types.h>

namespace erebus {

/**
 * Provides functionality to read files.
 */
class FileReader {

  public:
	/**
	 * Reads a file from the given path.
	 *
	 * @param path The path to the file to read
	 * @throws file_not_found in case the file doestn exist
	 * @return a pointer to a std::vector&lt;unsigned char&gt; with the bytes of the file. The caller is in charge to free the memory.
	 */
	static binVec* readFile(std::string path);
};

}//namespace erebus

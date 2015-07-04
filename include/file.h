#pragma once


#include <types.h>
#include <string>
#include <memory>

namespace erebus {

/**
 * This class holds the binary data of a file.
 */
class File {
	std::unique_ptr<binVec>	file_;
	std::string 		path_;

  public:
	/**
	 * Constructor.
	 *
	 * @param file a pointer to the binary data.
	 */
	File(binVec* file);

	/**
	 * Constructor.
	 *
	 * @param file a pointer to the binary data.
	 * @param path path to the read file. is empty if there is no path
	 */
	File(binVec* file,std::string path);

	/**
	 * Copy constructor.
	 */
	File(const File &obj);

	/**
	 * Destructor.
	 */
	virtual ~File();

	/**
	 * Returns the size of the file.
	 *
	 * @return size of the file
	 */
	unsigned int getFileSize() const;

	/**
	 * Returns the unsigned byte at the given index.
	 *
	 *@param index index to read byte from
	 *@return unsigned byte at index
	 */
	byte getUnsignedByteAt(unsigned int index) const;
};

}//namespace erebus
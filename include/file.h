#pragma once

#include <memory>

#include <types.h>

namespace erebus {

/**
 * This class holds the binary data of a file.
 */
class File {
	std::unique_ptr<binVec>	file_;

public:
	/**
	 * Constructor.
	 * 
	 * @param file a pointer to the binary data
	 */
	File(std::unique_ptr<binVec> file);
	
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
	
	/**
	 * Return the signed byte at the given index.
	 * 
	 * @param index index to read byte from
	 * @return signed byte at index
	 */
	sbyte getSignedByteAt(unsigned int index) const;
};
}
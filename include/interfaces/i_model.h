#pragma once

#include <string>

#include <file.h>

namespace erebus {

/**
 * The interface for the model.
 */
class IModel {

  public:
	/**
	 * Destructor.
	 */
	virtual ~IModel() {}

	/**
	 * Loads a file.
	 *
	 * @param path the path to read the file from.
	 */
	virtual void loadFile(std::string path)=0;

	/**
	 * Returns a pointer to the file.
	 *
	 * The pointer may be a nullptr.
	 *
	 * @return a pointer to the file
	 */
	virtual File* getFile() const=0;
};

}//namespace erebus

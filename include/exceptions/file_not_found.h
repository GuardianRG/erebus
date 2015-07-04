#pragma once

#include <stdexcept>

namespace erebus {

/**
 * This is a exception for the case a stated file doenst exist.
 */
class file_not_found : public std::runtime_error {

  public:
	/**
	 * Constructor.
	 */
	explicit file_not_found(const std::string& msg) : std::runtime_error(msg) {

	}
};

}//namespace erebus
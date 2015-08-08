#pragma once

#include <stdexcept>

namespace erebus {

/**
 * This class is an exception for the case an object has an invalid parent.
 */
class invalid_parent : public std::runtime_error {

  public:
	/**
	 * Constructor.
	 */
	explicit invalid_parent(const std::string& msg) : std::runtime_error(msg) {

	}
};
}//namespace erebus

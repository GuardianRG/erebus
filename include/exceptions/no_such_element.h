#pragma once

#include <string>
#include <stdexcept>

namespace erebus {
/**
 * This class is an exception for the case an object has an invalid parent.
 */
class no_such_element : public std::runtime_error {

  public:
	/**
	 * Constructor.
	 */
	explicit no_such_element(const std::string& msg) : std::runtime_error(msg) {

	}
};

}//namespace erebus

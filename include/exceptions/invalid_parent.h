#pragma once

#include <stdexcept>

namespace erebus {
class invalid_parent : public std::runtime_error {

  public:
	/**
	 * Constructor.
	 */
	explicit invalid_parent(const std::string& msg) : std::runtime_error(msg) {

	}
};
}//namespace erebus

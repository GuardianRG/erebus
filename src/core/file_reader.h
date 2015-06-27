#pragma once

#include <string>

#include "types.h"

namespace erebus {
	namespace core {

		class FileReader {
		public:
			static binVec readFile(std::string path);
		};
	}
}
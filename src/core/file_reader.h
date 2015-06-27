#pragma once

#include <string>

#include "types.h"

namespace erebus {

		class FileReader {
		public:
			static binVec readFile(std::string path);
		};
}
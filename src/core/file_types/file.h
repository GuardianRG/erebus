#pragma once

#include <memory>

#include "types.h"

namespace erebus {
	namespace core {
		

		class File {
			std::unique_ptr<binVec>	file_;
	
		public:
			File(binVec* file);
			~File();
	
			unsigned int getFileSize() const;
	
			byte getUnsignedByteAt(unsigned int index) const;
	
			sbyte getSignedByteAt(unsigned int index) const;
		};
	}
}
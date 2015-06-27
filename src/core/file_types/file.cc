#include "file.h"
#include "types.h"


namespace erebus {


File::File(binVec* file): file_(std::make_unique<binVec>(*file)) {
}

File::~File() {

}

unsigned int File::getFileSize() const {
	return file_->size();
}

byte File::getUnsignedByteAt(unsigned int index) const {
	return file_->at(index);
}

sbyte File::getSignedByteAt(unsigned int index) const {
	return static_cast<sbyte>(file_->at(index));
}

}
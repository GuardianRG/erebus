#include <file.h>
#include <types.h>
#include <string>
#include <memory>

namespace erebus {


File::File(std::unique_ptr<binVec> file): File(std::move(file),"") {
	
}
File::File(std::unique_ptr<binVec> file,std::string path): file_(std::move(file)),path_(path) {
	
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
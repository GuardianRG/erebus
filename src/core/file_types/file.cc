#include <file.h>
#include <types.h>
#include <string>
#include <memory>
#include <vector>

namespace erebus {

File::File(binVec* file): File(file,"") {

}

File::File(binVec* file,std::string path): file_(std::make_unique<binVec>(*file)),path_(path) {

}

File::File(const File &obj): file_(std::make_unique<binVec>(*(obj.file_.get()))),path_(obj.path_) {

}

File::~File() {

}

unsigned int File::getFileSize() const {
	return file_->size();
}

byte File::getUnsignedByteAt(unsigned int index) const {
	return file_->at(index);
}

}//namespace erebus
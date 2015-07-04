#include <model.h>

#include <string>
#include <file.h>
#include <file_reader.h>
#include <types.h>

namespace erebus {
Model::Model() {

}

Model::~Model() {

}

void Model::loadFile(std::string path) {
	binVec* file=FileReader::readFile(path);
	file_=std::unique_ptr<File>(new File(file,path));
}

File* Model::getFile() const {
	return file_.get();
}

}//namespace erebus
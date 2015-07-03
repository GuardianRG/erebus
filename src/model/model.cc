#include <model.h>

#include <string>
#include <file.h>
#include <file_reader.h>
#include <types.h>
#include <memory>

namespace erebus {
Model::Model() {

}

Model::~Model() {
	
}

void Model::loadFile(std::string path) {
	std::unique_ptr<binVec> file=FileReader::readFile(path);
	file_=std::unique_ptr<File>(new File(std::move(file),path));
}

File* Model::getFile() const {
	return file_.get();
}

}
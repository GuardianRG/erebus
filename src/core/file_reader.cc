#include <string>
#include <fstream>
#include <iterator>

#include "types.h"
#include "file_reader.h"
#include "exceptions/file_not_found.h"

namespace erebus {

binVec FileReader::readFile(std::string path) {
	std::ifstream file(path, std::ios::binary);

	if(!file.good()) {

		file.close();
		throw new file_not_found(path+" does not exist!");
	}

	file.unsetf(std::ios::skipws);

	std::streampos fileSize;


	file.seekg(0,std::ios::end);
	fileSize=file.tellg();
	file.seekg(0,std::ios::beg);

	binVec vec;
	vec.reserve(fileSize);

	vec.insert(vec.begin(), std::istream_iterator<byte>(file),std::istream_iterator<byte>());

	file.close();

	return vec;
}

}
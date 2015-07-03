#pragma once

#include <string>
#include <file.h>

namespace erebus {

class IModel {
public:
	virtual ~IModel() {}
	virtual void loadFile(std::string path)=0;
	virtual File* getFile() const=0;
};

}
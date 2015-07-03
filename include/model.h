#pragma once

#include <file.h>
#include <memory>
#include <interfaces/i_model.h>

namespace erebus {

class Model :public IModel {
	std::unique_ptr<File> file_;
public:
	Model();
	~Model();
	
	void loadFile(std::string path) override;
	File* getFile() const override;
};

}
#pragma once

#include <file.h>
#include <memory>
#include <interfaces/i_model.h>

namespace erebus {

/**
 * Is a concrete model.
 */
class Model :public IModel {
	std::unique_ptr<File> file_;
  public:
	/**
	 * Constructor.
	 */
	Model();

	/**
	 * Copy Constructor.
	 */
	Model(const Model &obj)=delete;

	/**
	 * Destructor.
	 */
	~Model();

	/**
	 * See IModel::loadFile(std::string path).
	 */
	void loadFile(std::string path) override;

	/**
	 * See IModel::getFile().
	 */
	File* getFile() const override;
};

}
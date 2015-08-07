#pragma once

#include <string>

namespace erebus {

class IGUIManager;

}

namespace erebus {

/**
 * This class is the base class of every gui object.
 */
class IGUIObject {

  public:

	/**
	 * Destructor.
	 */
	~IGUIObject() {}

	/**
	 * Returns the classname.
	 *
	 * The class name should be optimally the actual name of the class but can be
	 * any unique string.
	 *
	 * @return the name of the class
	 */
	virtual std::string classname()=0;

	/**
	 * Returns a unique id for every instance.
	 *
	 * This could be e.g. the pointer to the class but it has not has to be as long as
	 * the id is guaranteed to be unique for every instance.
	 *
	 * @return a unique id
	 */
	virtual std::size_t getID()=0;

	/**
	 * Sets the manager.
	 *
	 * @param manager the manager to set
	 */
	virtual void setGUIManager(IGUIManager& manager)=0;

	/**
	 * Returns the gui Manager.
	 *
	 * @return the gui manager
	 */
	virtual IGUIManager& getGUIManager()=0;
};

}//namespace erebus

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
	~IGUIObject() {}

	/**
	 * Returns the classname.
	 *
	 * @return the name of the class.
	 */
	virtual std::string classname()=0;

	/**
	 * Returns a unique id for a instance.
	 *
	 * @return a unique id
	 */
	virtual std::size_t getID()=0;

	/**
	 * Sets the manager.
	 *
	 * @param manager the manager
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

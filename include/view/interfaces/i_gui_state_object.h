#pragma once

namespace erebus {

/**
 * This class is a state object.
 *
 * Since the gui manager is purely defined abstract and gets implemented
 * by a statically linked file there is no way for the gui manager to save
 * variables/states and share them with other methods internally.
 * To solve this issue this class exists.
 */
class IGUIStateObject {
  public:
	/**
	 * Destructor.
	 */
	virtual ~IGUIStateObject() {}
};


}//namespace erbus
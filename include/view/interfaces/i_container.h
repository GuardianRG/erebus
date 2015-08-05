#pragma once

#include <string>

#include <view/interfaces/i_gui_object.h>

namespace erebus {
class IContainer :public IGUIObject {
  public:
	~IContainer() {}

	/**
	 * Whether this window contains the given widget.
	 *
	 * Is even true if thw window itsel has the id.
	 *
	 * @return true if the window contains this widget
	 */
	virtual bool containsWidget(std::size_t id)=0;

	/**
	 * Returns the parent of the id.
	 *
	 * If the parent isnt found nullptr is returned and if
	 * id is a window the window will be returned.
	 *
	 * @return the parent of id
	 */
	virtual IGUIObject* getParentOf(std::size_t id)=0;

};
}//namespace erebus

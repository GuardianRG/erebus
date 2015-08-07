#pragma once

#include <string>

#include <view/interfaces/i_gui_object.h>

namespace erebus {

/**
 * This class is the base interface for all gui elements that can contain
 * other gui elements.
 */
class IContainer :public IGUIObject {

  public:
	/**
	 * Destructor.
	 */
	~IContainer() {}

	/**
	 * Whether this container contains the widget with the given id.
	 *
	 * @return true if the container contains this widget
	 */
	virtual bool containsWidget(std::size_t id)=0;

	/**
	 * Returns the parent container of the the widget with the given id.
	 *
	 * If this container does not contain the widget, nullptr is returned.
	 *
	 * @return the parent container of the widget with the given id
	 */
	virtual IGUIObject* getParentOf(std::size_t id)=0;

};

}//namespace erebus

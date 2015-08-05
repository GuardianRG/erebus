#pragma once

#include <string>

#include <view/interfaces/i_gui_manager.h>
#include <view/interfaces/i_gui_object.h>

namespace erebus {

/**
 * This class is the interface for very window.
 */
class IWindow :virtual public IGUIObject {
  public:
	/**
	 * Destructor.
	 */
	virtual ~IWindow() {};

	/**
	 * Sets the title of the window.
	 *
	 * @param title title of the window
	 */
	virtual void setTitle(std::string title)=0;

	/**
	 * Returns the title of the window.
	 *
	 * @return the title of the window
	 */
	virtual std::string getTitle() const=0;

	/**
	 * Sets the gui manager that this window holds.
	 *
	 * @param manager the guin manager
	 */
	virtual void setGUIManager(IGUIManager& manager)=0;

	/**
	 * Sets the preferred size of the window.
	 *
	 * @param width preferred width
	 * @param height preferred height
	 */
	virtual void setPreferredSize(int width,int height)=0;

	/**
	 * Maximizes the window.
	 */
	virtual void maximize()=0;

	/**
	 * unmaximizes the window.
	 */
	virtual void unmaximize()=0;
	
	/**
	 * Whether this window contains the given widget.
	 * 
	 * Is even true if thw window itsel has the id.
	 * 
	 * @return true if the window contains this widget
	 */
	virtual bool containsWidget(std::size_t id)=0;

	/**
	 * Closes the window.
	 *
	 * WARNING: This window will commit suicide.
	 */
	virtual void close()=0;
};

}//namespace erbus

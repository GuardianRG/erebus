#pragma once


#include <string>

namespace erebus {

/**
 * This class is the interface for very window.
 */
class IWindow {
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
	 * Closes the window.
	 *
	 * WARNING: This window will commit suicide.
	 */
	virtual void close()=0;
};

}//namespace erbus

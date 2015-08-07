#pragma once

#include <string>
#include <memory>

namespace erebus {
class IWindow;
class IGUIObject;
class IView;
class IViewWindow;
}

namespace erebus {

/**
 * This enum holds the dirfferent error levels for the message boxes.
 */
enum class ErrorLevel {
	/**
	 * The message is a information.
	 */
	INFO,
	/**
	 * The message is a warning.
	 */
	WARNING,
	/**
	 * The message is an error.
	 */
	ERROR
};

/**
 * This class is the interface for a gui manager.
 */
class IGUIManager {
  public:
	virtual ~IGUIManager() {}

	/**
	 * Shows a Messagedialog without locking any window.
	 *
	 * @param primaryText the main text
	 * @param secondaryText the secondary text
	 * @param errorLevel the error level of the message
	 */
	virtual void showMessageDialog(std::string primaryText,std::string secondaryText,
	                               ErrorLevel errorLevel)=0;


	/**
	* Shows a Messagedialog.
	*
	* @param id id of the thing that requests a messagedialog
	* @param primaryText the main text
	* @param secondaryText the secondary text
	* @param errorLevel the error level
	*/
	virtual void showMessageDialog(std::size_t id,std::string primaryText,std::string secondaryText,
	                               ErrorLevel errorLevel)=0;
	/**
	 * Runs the gui aka makes the main window to show up.
	 */
	virtual void runGUI()=0;

	/**
	 * Adds a window to the application.
	 *
	 * @param window the window to add
	 * @param makePersistent if true, the application will close if this window as closed
	 */
	virtual IWindow& addWindow(std::unique_ptr<IWindow> window,bool makePersistent)=0;

	/**
	 * Destroys the reference the application has to this window.
	 *
	 * The window should be properly closed before calling this method.
	 *
	 * @param window the window to destroy
	 */
	virtual void destroyWindow(IWindow& window)=0;

	/**
	 * Joins the container which contains the widget with the ID id.
	 *
	 * @param id the id which parent container should get joined
	 */
	virtual void joinContainer(std::size_t id)=0;

	virtual IViewWindow& createNewViewWindow()=0;

	virtual void moveViewToNewWindow(IView& view)=0;

	virtual IGUIObject* getParentOf(std::size_t id)=0;

	/**
	 * Returns a unqiue id for the gui manager.
	 *
	 * @return unqiue id for the gui manager
	 */
	virtual long getID()=0;
};

}//namespace erebus

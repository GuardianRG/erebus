#pragma once

#include <string>
#include <memory>

namespace erebus {

class IWindow;
class IGUIObject;
class IView;
class IViewWindow;
class ViewPreferencesManager;

}

namespace erebus {

/**
 * This enum holds the different error levels for the message boxes.
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
	 * Shows a Messagedialog without locking any specific window.
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
	* The window which contains the widget with the given id gets locked.
	*
	* @param id id of the object that requests a messagedialog
	* @param primaryText the main text
	* @param secondaryText the secondary text
	* @param errorLevel the error level
	*/
	virtual void showMessageDialog(std::size_t id,std::string primaryText,std::string secondaryText,
	                               ErrorLevel errorLevel)=0;

	/**
	 * Shows the gui.
	 */
	virtual void runGUI()=0;

	/**
	 * Adds a window to the application.
	 *
	 * @param window the window to add
	 * @param makePersistent if true, the application will close if this window is closed aswell
	 */
	virtual IWindow& addWindow(std::unique_ptr<IWindow> window,bool makePersistent)=0;

	/**
	 * Destroys the window.
	 *
	 * This method needs to be called since this object has ownership of every window
	 * created.
	 *
	 * The window should be properly closed before calling this method.
	 *
	 * @param window the window to destroy
	 */
	virtual void destroyWindow(IWindow& window)=0;

	/**
	 * Joins the container which contains the container which contains the widget with the given id.
	 *
	 * @param id the id of the widget
	 */
	virtual void joinContainer(std::size_t id)=0;

	/**
	 * Creates a new view window and shows it.
	 */
	virtual IViewWindow& createNewViewWindow()=0;
	
	/**
	 * Returns the manager that holds the view preferences.
	 * 
	 * @return the manager that holds the view preferences.
	 */
	virtual ViewPreferencesManager& getViewPreferences()=0;

	/**
	 * Creats a new view window and moves the given view to this new window.
	 *
	 * It should be ensured that the view is ready for getting moved to the new window.
	 * (is not contained in any other container)
	 *
	 * @param view the view to be moved
	 */
	virtual void moveViewToNewWindow(IView& view)=0;

	/**
	 * Returns the parent container of the widget with the given id.
	 *
	 * @param id the id of the widget whose parent is to be determined
	 */
	virtual IGUIObject* getParentOf(std::size_t id)=0;

};

}//namespace erebus

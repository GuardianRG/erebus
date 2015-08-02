#pragma once

#include <memory>
#include <vector>

#include <view/interfaces/i_main_window.h>
#include <view/interfaces/i_gui_state_object.h>
#include <view/interfaces/i_view.h>
#include <view/interfaces/i_window.h>

#include <model.h>
#include <view/view_preferences.h>


namespace erebus {
	
	
	enum class ErrorLevel {
		INFO,
		ERROR	
	};

/**
 * This class handels the gui. The concrete implementation
 * gets statically linked on compile time.
 */
class GUIManager {
	int&					argc_;
	char**& 				argv_;

	std::shared_ptr<Model>			model_;

	std::unique_ptr<IGUIStateObject>	stateObject_;
	
	std::vector<std::unique_ptr<IWindow>> 	windows_;

	std::unique_ptr<ViewPreferences>	viewPreferences_;

  public:
	  GUIManager(std::shared_ptr<Model> model,int& argc, char**& argv);

	/**
	 * Copy Constructor.
	 *
	 * Copying the whole gui has no sense.
	 */
	GUIManager(const GUIManager &obj)=delete;

	/**
	 * Move Constructor.
	 */
	GUIManager( GUIManager&& ) = default;

	/**
	 * Copy assignment operator.
	 *
	 * Copying the whole gui has no sense.
	 */
	GUIManager& operator=(const GUIManager&)=delete;

	/**
	 * Move assignment operator.
	 */
	GUIManager& operator=(GUIManager&&) = default;

	/**
	 * Destructor.
	 */
	~GUIManager();

	/**
	 * Shows the gui.
	 *
	 * This method doesnt return until the gui is closed.
	 */
	void runGUI();

	/**
	 * Adds a new window to the manager.
	 *
	 * Those windows persist even when the main window is closed.
	 * The basically bcome another main window.
	 *
	 * @param window window to add
	 */
	void addWindow(IWindow& window);
	
	void loadViewPreferences();

	/**
	 * Creates a new window and adds the view to it.
	 *
	 * @param view view to add to the new window
	 */
	void moveViewToNewWindow(IView& view);

	/**
	 * Destroys the window.
	 *
	 * This method only destroys the given window.
	 * For hiding it the caller is responsible.
	 *
	 * After this method window is a invalid pointer and will be ste to nullptr.
	 *
	 * @param window the window to destroy
	 */
	void deleteWindow(IWindow* window);

	/**
	 * Shows a info dialog.
	 *
	 * @param title the title of the dialog
	 * @param text the info text
	 */
	void showInfoDialog(std::string title,std::string text,ErrorLevel el);
};


}//namespace erbus

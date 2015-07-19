#pragma once

#include <view/interfaces/i_main_window.h>
#include <view/interfaces/i_gui_state_object.h>
#include <view/interfaces/i_view.h>
#include <view/interfaces/i_window.h>

#include <model.h>


namespace erebus {

/**
 * This class handels the gui. The concrete implementation
 * gets statically linked on compile time.
 */
class GUIManager {
	static GUIManager*	guiManager_;

	int&			argc_;
	char**& 		argv_;

	Model*			model_;

	IMainWindow*		mainWindow_;

	IGUIStateObject*	stateObject_;

	GUIManager(Model* model,int& argc, char**& argv);

  public:
	/**
	 * Creates the singleton object.
	 *
	 * Theis method only builds the gui but doesnt show it.
	 * To show the gui call GUIManager::runGUI.
	 *
	 * @param model The model the gui shall operate on
	 * @param argc number of console arguments
	 * @param argv console arguments
	 */
	static GUIManager* create(Model* model,int& argc, char**& argv);

	/**
	 * Returns the singleton of this class.
	 *
	 * @return singleton of this class
	 */
	static GUIManager* getInstance();

	/**
	 * Copy Constructor.
	 *
	 * Deleted until needed.
	 */
	GUIManager(const GUIManager &obj)=delete;

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
	 * @param window window to add
	 */
	void addWindow(IWindow* window);

	/**
	 * Creates a new window and adds the view to it.
	 *
	 * @param view view to add to the new window
	 */
	void moveViewToNewWindow(IView* view);
};

}//namespace erbus

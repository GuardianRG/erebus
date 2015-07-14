#pragma once

#include <view/interfaces/i_main_window.h>
#include <view/interfaces/i_gui_state_object.h>

#include <model.h>


namespace erebus {

/**
 * This class handels the gui. The concrete implementation
 * gets statically linked on compile time.
 */
class GUIManager {
	int&			argc_;
	char**& 		argv_;

	Model*			model_;

	IMainWindow*		mainWindow_;

	IGUIStateObject*	stateObject_;

  public:
	/**
	 * Constructor.
	 *
	 * The constructor only builds the gui but doesnt show it.
	 * To show the gui call GUIManager::runGUI.
	 *
	 * @param model The model the gui shall operate on
	 * @param argc number of console arguments
	 * @param argv console arguments
	 */
	GUIManager(Model* model,int& argc, char**& argv);

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
};

}//namespace erbus
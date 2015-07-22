#pragma once

#include <memory>

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
	static std::unique_ptr<GUIManager>	guiManager_;

	int&					argc_;
	char**& 				argv_;

	std::shared_ptr<Model>			model_;

	IGUIStateObject*			stateObject_;

	GUIManager(std::shared_ptr<Model> model,int& argc, char**& argv);

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
	static GUIManager* create(std::shared_ptr<Model> model,int& argc, char**& argv);

	/**
	 * Returns the singleton of this class.
	 *
	 * @return singleton of this class
	 */
	static GUIManager* getInstance();

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

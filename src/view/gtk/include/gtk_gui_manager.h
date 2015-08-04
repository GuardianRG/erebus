#pragma once

#include <gtkmm/application.h>
#include <gtkmm/window.h>

#include <string>
#include <vector>
#include <memory>

#include <view/interfaces/i_gui_manager.h>

namespace erebus {
class IWindow;
}

namespace erebus {

/**
 * This class is the gui manager for the gtkmm library.
 */
class GTK_GUIManager:public IGUIManager {
	Glib::RefPtr<Gtk::Application> 			application_;

	std::unique_ptr<Gtk::Window>			dummyWindow_;
	std::vector<std::unique_ptr<IWindow>>		windows_;

	bool	 					isInitialized_;

	void showMessageDialogPr(Gtk::Window& window,std::string primaryText,std::string secondaryText,
	                         ErrorLevel errorLevel);

  public:
	/**
	 * The package name of this application.
	 */
	static const std::string STD_APP_ID;

	/**
	 * Constructor.
	 */
	GTK_GUIManager();

	/**
	 * Copy constructor.
	 *
	 * Copying the whole gui has no sense.
	 */
	GTK_GUIManager(const GTK_GUIManager &obj)=delete;

	/**
	 * Move Constructor.
	 *
	 * Moving the whole gui has no sense.
	 */
	GTK_GUIManager( GTK_GUIManager&& )=delete;

	/**
	 * Copy assignment operator.
	 *
	 * Copying the whole gui has no sense.
	 */
	GTK_GUIManager& operator=(const GTK_GUIManager&)=delete;

	/**
	 * Move assignment operator.
	 *
	 * Moving the whole gui has no sense.
	 */
	GTK_GUIManager& operator=(GTK_GUIManager&&)=delete;

	/**
	 * Destructor.
	 */
	~GTK_GUIManager();


	/**
	 * Initializes the gui.
	 *
	 * This method has to be called before every other method.
	 *
	 * @param argc command line arg argc
	 * @param argv command line arg argv
	 */
	void initialize(int argc,char** argv);

	/**
	 * See IGUIManager::showMessageDialog
	 */
	void showMessageDialog(std::string primaryText,std::string secondaryText,
	                       ErrorLevel errorLevel)override;

	/**
	 * See IGUIManager::showMessageDialog
	 */
	void showMessageDialog(IWindow& window,std::string primaryText,std::string secondaryText,
	                       ErrorLevel errorLevel)override;

	/**
	 * See IGUIManager::runGUI
	 */
	void runGUI()override;

	/**
	 * See IGUIManager::addWindow
	 */
	IWindow& addWindow(std::unique_ptr<IWindow> window,bool makePersistent)override;

	/**
	 * See IGUIManager::destroyWindow
	 */
	void destroyWindow(IWindow& window)override;

	/**
	 * See IGUIManager::getID
	 */
	long getID()override;

};
}//namespace erebus

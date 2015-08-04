#pragma once

#include <memory>

namespace erebus {

class IMainWindowPresenter;
class IGUIManager;
class GTK_MainWindow;

}

namespace erebus {

/**
 * This class is a window factory.
 */
class GTK_WindowFactory {
	GTK_WindowFactory();
  public:
	/**
	 * Destructor.
	 */
	~GTK_WindowFactory();

	/**
	 * Creats a GTK_MainWindow.
	 *
	 * @param manager the manager this window belongs to
	 * @param presenter the presenter to use
	 */
	static std::unique_ptr<GTK_MainWindow> createMainWindow(IGUIManager& manager,
	        std::unique_ptr<IMainWindowPresenter> presenter);

	/**
	 * Creates a GTK_MainWindow.
	 *
	 * @param manager the manager this window belongs to
	 */
	static std::unique_ptr<GTK_MainWindow> createMainWindow(IGUIManager& manager);

};


}//namespace erebus

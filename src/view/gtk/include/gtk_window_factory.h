#pragma once

#include <memory>

namespace erebus {

class IMainWindowPresenter;
class IViewWindowPresenter;
class IGUIManager;
class GTK_MainWindow;
class GTK_ViewWindow;
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

	/**
	 * Creats a GTK_ViewWindow.
	 *
	 * @param manager the manager this window belongs to
	 * @param presenter the presenter to use
	 */
	static std::unique_ptr<GTK_ViewWindow> createViewWindow(IGUIManager& manager,
	        std::unique_ptr<IViewWindowPresenter> presenter);

	/**
	 * Creates a GTK_ViewWindow.
	 *
	 * @param manager the manager this window belongs to
	 */
	static std::unique_ptr<GTK_ViewWindow> createViewWindow(IGUIManager& manager);

};


}//namespace erebus

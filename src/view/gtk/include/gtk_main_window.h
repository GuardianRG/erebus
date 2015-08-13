#pragma once

#include <gtkmm/builder.h>
#include <glibmm/refptr.h>
#include <gtkmm/viewport.h>

#include <memory>
#include <string>

#include <i_main_window.h>

#include <gtk_window.h>

namespace erebus {

class IMainWindowPresenter;
class GTK_ViewContainer;
class IGUIManager;
class IGUIObject;

}

namespace erebus {

/**
 * This class is the main window.
 */
class GTK_MainWindow : public GTK_Window, public IMainWindow {
	std::unique_ptr<IMainWindowPresenter>	presenter_;

	Gtk::Viewport* 				base_;
	std::unique_ptr<GTK_ViewContainer>	basicViewContainer_;

	bool 					isInitialized_;


	void on_menu_view_new_window_click();
	void on_menu_view_save_preferences_click();

  public:
	/**
	 * The classname that gets returned by GTK_MainWindow::classname.
	 */
	static const std::string CLASSNAME;

	/**
	 * Constructor.
	 *
	 * This Constructor is needed for building this window from a builder.
	 */
	GTK_MainWindow(BaseObjectType* cobject,
	               const Glib::RefPtr<Gtk::Builder>& refBuilder);

	/**
	 * Copy constructor.
	 *
	 * Cant be copied since Gtk::Window cant be copied.
	 */
	GTK_MainWindow(const GTK_MainWindow &obj)=delete;

	/**
	 * Move Constructor.
	 *
	 * Cant be moved since Gtk::Window cant be moved.
	 */
	GTK_MainWindow( GTK_MainWindow&& )=delete;

	/**
	 * Copy assignment operator.
	 *
	 * Cant be copied since Gtk::Window cant be copied.
	 */
	GTK_MainWindow& operator=(const GTK_MainWindow&)=delete;

	/**
	 * Move assignment operator.
	 *
	 * Cant be copied since Gtk::Window cant be moved.
	 */
	GTK_MainWindow& operator=(GTK_MainWindow&&)=delete;

	/**
	 * Destructor.
	 */
	~GTK_MainWindow();


	/**
	 * See IMainWindow::containsWidget.
	 */
	bool containsWidget(std::size_t id)override;

	/**
	 * See IMainWindow::getParentOf.
	 */
	IGUIObject* getParentOf(std::size_t id)override;

	/**
	 * See IMainWindow::classname.
	 */
	virtual std::string classname()override;

	/**
	 * Sets the presenter.
	 *
	 * @param presenter the presenter to set
	 */
	void setPresenter(std::unique_ptr<IMainWindowPresenter> presenter);

	/**
	 * Initializes the window.
	 *
	 * This method should be called before every other method.
	 *
	 * @param manager the manager to use
	 */
	void initialize(IGUIManager& manager);
};

}//namespace erebus

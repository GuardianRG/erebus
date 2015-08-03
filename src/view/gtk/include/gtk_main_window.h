#pragma once

#include <gtkmm/builder.h>
#include <glibmm/refptr.h>

#include <memory>

#include <view/interfaces/i_main_window.h>

#include <gtk_window.h>

namespace erebus {
class IMainWindowPresenter;
}

namespace erebus {

/**
 * This class is the main window.
 */
class GTK_MainWindow : public GTK_Window, public IMainWindow {
	std::unique_ptr<IMainWindowPresenter>	presenter_;


	//GTK_ViewContainer*	basicView_;

	//void on_menu_view_save_click();
	//void on_menu_view_show_tabs_click();
  protected:
	/**
	 * See GTK_Window::getPresenter
	 */
	IWindowPresenter& getPresenter()override;

  public:
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
	 * See IMainWindow::setPresenter
	 */
	void setPresenter(std::unique_ptr<IMainWindowPresenter> presenter);

	/**
	 * See IMainWindow::close
	 */
	void close() override;
};
}//namespace erebus

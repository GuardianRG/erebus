#pragma once

#include <gtkmm.h>

#include <memory>

#include <presenter/interfaces/i_main_window_presenter.h>
#include <view/interfaces/i_main_window.h>

#include <gtk_window.h>
#include <gtk_view_container.h>

namespace erebus {

/**
 * This class is the main window.
 */
class GTK_MainWindow : public GTK_Window, public IMainWindow {
	std::unique_ptr<IMainWindowPresenter>	presenter_;


	GTK_ViewContainer*	basicView_;

	void on_menu_view_save_click();
	void on_menu_view_show_tabs_click();
  protected:
	IWindowPresenter& getPresenter();
  public:
	/**
	 * Constructor.
	 *
	 * This Constructor is need for building this window from a builder.
	 */
	GTK_MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder);

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
	 * See IMainWindow::setTitle
	 */
	void setTitle(std::string title) override;
	

	/**
	 * See IMainWindow::getTitle
	 */
	std::string getTitle() const override;

	/**
	 * See IMainWindow::setPreferredSize
	 */
	void setPreferredSize(int width,int height) override;

	/**
	 * See IMainWindow::maximize
	 */
	void maximize() override;

	/**
	 * See IMainWindow::unmaximize
	 */
	void unmaximize() override;

	/**
	 * See IMainWindow::close
	 */
	void close() override;
};
}//namespace erebus

#pragma once

#include <gtkmm.h>

#include <presenter/interfaces/i_main_window_presenter.h>
#include <presenter/interfaces/i_presenter.h>
#include <view/interfaces/i_main_window.h>

#include <gtk_view_container.h>

namespace erebus {

	/**
	 * This class is the main window.
	 */
class GTK_MainWindow : public Gtk::Window, public IMainWindow {
	IMainWindowPresenter*	presenter_;


	GTK_ViewContainer*	basicView_;

  public:
	  /**
	   * Constructor.
	   */
	GTK_MainWindow();
	
	/**
	 * Constructor.
	 * 
	 * This Constructor is need for building this window from a builder.
	 */
	GTK_MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder);
	
	/**
	 * Copy constructor.
	 * 
	 * Deleted until needed.
	 */
	GTK_MainWindow(const GTK_MainWindow &obj)=delete;
	
	/**
	 * Destructor.
	 */
	~GTK_MainWindow();


	/**
	 * See IMainWindow::setPresenter
	 */
	void setPresenter(IPresenter* presenter) override;
	
	/**
	 * See IMainWindow::setTitle
	 */
	void setTitle(std::string title) override;
	
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
};
}//namespace erebus
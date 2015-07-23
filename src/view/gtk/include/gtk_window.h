#pragma once

#include <gtkmm.h>

#include <string>

#include <view/interfaces/i_window.h>
#include <presenter/interfaces/i_window_presenter.h>

namespace erebus {

/**
 * This class is a simple gtk window.
 */
class GTK_Window:public Gtk::Window,public IWindow {
	IWindowPresenter*	presenter_;
  public:
	/**
	 * Construcctor.
	 */
	GTK_Window();

	/**
	 * Copy constructor.
	 *
	 * Cant be copied since Gtk::Viewport cant be copied-
	 */
	GTK_Window(const GTK_Window &obj)=delete;

	/**
	 * Move Constructor.
	 *
	 * Cant be copied since Gtk::Viewport cant be copied-
	 */
	GTK_Window( GTK_Window&& )=delete;

	/**
	 * Copy assignment operator.
	 *
	 * Cant be copied since Gtk::Viewport cant be copied-
	 */
	GTK_Window& operator=(const GTK_Window&)=delete;

	/**
	 * Move assignment operator.
	 *
	 * Cant be copied since Gtk::Viewport cant be copied-
	 */
	GTK_Window& operator=(GTK_Window&&)=delete;

	/**
	 * Destructor.
	 */
	virtual ~GTK_Window();

	/**
	 * See IWindow::setTitle
	 */
	void setTitle(std::string title) override;

	std::string getTitle() const override;

	/**
	 * See IWindow::setPreferredSize
	 */
	void setPreferredSize(int width,int height) override;

	/**
	 * See IWindow::maximize
	 */
	void maximize() override;

	/**
	 * See IWindow::unmaximize
	 */
	void unmaximize() override;
};
}//namespace erebus

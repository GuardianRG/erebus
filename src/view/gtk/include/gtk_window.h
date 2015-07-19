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
	 * Deleted until needed.
	 */
	GTK_Window(const GTK_Window &obj)=delete;

	/**
	 * Destructor.
	 */
	virtual ~GTK_Window();

	/**
	 * See IWindow::setPresenter
	 */
	void setPresenter(IPresenter* presenter) override;

	/**
	 * See IWindow::setTitle
	 */
	void setTitle(std::string title) override;

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

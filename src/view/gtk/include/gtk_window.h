#pragma once

#include <gtkmm.h>

#include <string>

#include <view/interfaces/i_window.h>
#include <presenter/interfaces/i_window_presenter.h>

namespace erebus {

/**
 * This class is a simple gtk window.
 */
class GTK_Window:public Gtk::Window,virtual public IWindow {

  protected:
	virtual IWindowPresenter& getPresenter()=0;
  public:
	/**
	 * Construcctor.
	 */
	GTK_Window(BaseObjectType* cobject);

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
	virtual void setTitle(std::string title) override;

	virtual std::string getTitle() const override;

	/**
	 * See IWindow::setPreferredSize
	 */
	virtual void setPreferredSize(int width,int height) override;

	/**
	 * See IWindow::maximize
	 */
	virtual void maximize() override;

	/**
	 * See IWindow::unmaximize
	 */
	virtual void unmaximize() override;

	virtual void close() override;
};
}//namespace erebus

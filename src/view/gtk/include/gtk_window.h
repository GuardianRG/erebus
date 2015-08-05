#pragma once

#include <gtkmm/window.h>

#include <string>

#include <view/interfaces/i_window.h>

namespace erebus {

class IGUIManager;
class IWindowPresenter;

}

namespace erebus {

/**
 * This class is the base gtk window.
 */
class GTK_Window:public Gtk::Window,virtual public IWindow {

  protected:
	/**
	 * Holds the pointer to the manager of the gui,
	 */
	IGUIManager*	guiManager_;

	/**
	 * Returns the presenter.
	 *
	 * @return the presenter
	 */
	virtual IWindowPresenter& getPresenter()=0;

  public:
	/**
	 * Construcctor.
	 *
	 * This constructor is needed for bulding subclasses from a builder.
	 */
	GTK_Window(BaseObjectType* cobject);

	/**
	 * Copy constructor.
	 *
	 * Cant be copied since Gtk::Window cant be copied.
	 */
	GTK_Window(const GTK_Window &obj)=delete;

	/**
	 * Move Constructor.
	 *
	 * Cant be copied since Gtk::Window cant be copied.
	 */
	GTK_Window( GTK_Window&& )=delete;

	/**
	 * Copy assignment operator.
	 *
	 * Cant be copied since Gtk::Window cant be copied.
	 */
	GTK_Window& operator=(const GTK_Window&)=delete;

	/**
	 * Move assignment operator.
	 *
	 * Cant be copied since Gtk::Window cant be copied.
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

	/**
	 * See IWindow::getTitle
	 */
	std::string getTitle() const override;

	/**
	 * See IWindow::classname
	 */
	virtual std::string classname()override;

	/**
	 * See IWindow::setPreferredSize
	 */
	void setPreferredSize(int width,int height) override;

	/**
	 * See IWindow::maximize
	 */
	void maximize() override;

	/**
	 * See IWindow::setGUIManager
	 */
	void setGUIManager(IGUIManager& manager)override;

	/**
	 * See IWindow::getGUIManager
	 */
	IGUIManager& getGUIManager()override;

	/**
	 * See IWindow::unmaximize
	 */
	void unmaximize() override;

	/**
	 * See IWindow::getID
	 */
	std::size_t getID()override;

	/**
	 * See IWindow::close
	 */
	virtual void close() override;
};
}//namespace erebus

#pragma once

#include <gtkmm.h>

#include <string>
#include <memory>

#include <view/interfaces/i_view_window.h>
#include <view/interfaces/i_view.h>
#include <presenter/interfaces/i_view_window_presenter.h>

#include <gtk_window.h>
#include <gtk_view_container.h>

namespace erebus {

class GTK_ViewWindow:virtual public GTK_Window,virtual public IViewWindow {
	std::unique_ptr<IViewWindowPresenter>	presenter_;

	GTK_ViewContainer*	container_;
  protected:
	IWindowPresenter& getPresenter();
  public:
	/**
	 * Constructor.
	 */
	GTK_ViewWindow(BaseObjectType* cobject,
	               const Glib::RefPtr<Gtk::Builder>& refBuilder);

	/**
	 * Copy constructor.
	 *
	 * Cant be copied since Gtk::Window cant be copied.
	 */
	GTK_ViewWindow(const GTK_ViewWindow &obj)=delete;

	/**
	 * Move Constructor.
	 *
	 * Cant be copied since Gtk::Window cant be copied.
	 */
	GTK_ViewWindow( GTK_ViewWindow&& )=delete;

	/**
	 * Copy assignment operator.
	 *
	 * Cant be copied since Gtk::Window cant be copied.
	 */
	GTK_ViewWindow& operator=(const GTK_ViewWindow&)=delete;

	/**
	 * Move assignment operator.
	 *
	 * Cant be copied since Gtk::Window cant be copied.
	 */
	GTK_ViewWindow& operator=(GTK_ViewWindow&&)=delete;

	/**
	 * Destructor.
	 */
	~GTK_ViewWindow();

	/**
	 * See IViewWindow::setPresenter
	 */
	void setPresenter(std::unique_ptr<IViewWindowPresenter> presenter);

	/**
	 * See IViewWindow::setTitle
	 */
	void setTitle(std::string title) override;


	/**
	 * IViewWindow::getTitle
	 */
	std::string getTitle() const override;

	/**
	 * See IViewWindow::setPreferredSize
	 */
	void setPreferredSize(int width,int height) override;

	/**
	 * See IViewWindow::maximize
	 */
	void maximize() override;

	/**
	 * See IViewWindow::unmaximize
	 */
	void unmaximize() override;

	/**
	 * See IViewWindow::addView
	 */
	IViewContainer& getBasicViewContainer()override;

	/**
	 * See IViewWindow::isEmpty
	 */
	bool isEmpty()const override;

	/**
	 * See IViewWindow::close
	 */
	void close()override;
};


}//namespace erebus

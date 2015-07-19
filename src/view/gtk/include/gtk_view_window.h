#pragma once

#include <gtkmm.h>

#include <string>

#include <view/interfaces/i_view_window.h>
#include <view/interfaces/i_view.h>
#include <presenter/interfaces/i_view_window_presenter.h>

#include <gtk_view_container.h>

namespace erebus {

class GTK_ViewWindow:public Gtk::Window,public IViewWindow {
	IViewWindowPresenter*	presenter_;

	GTK_ViewContainer*	container_;
  public:
	/**
	 * Constructor.
	 */
	GTK_ViewWindow();

	/**
	 * Constructor.
	 */
	GTK_ViewWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder);

	/**
	 * Copy Constructor.
	 *
	 * Deleted until needed.
	 */
	GTK_ViewWindow(const GTK_ViewWindow &obj)=delete;

	/**
	 * Destructor.
	 */
	~GTK_ViewWindow();

	/**
	 * See IViewWindow::setPresenter
	 */
	void setPresenter(IPresenter* presenter) override;

	/**
	 * See IViewWindow::setTitle
	 */
	void setTitle(std::string title) override;

	/**
	 * IViewWindow::getTitle
	 */
	std::string getTitle() override;

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
	void addView(IView* view);
};


}//namespace erebus

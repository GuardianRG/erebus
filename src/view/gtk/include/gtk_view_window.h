#pragma once

#include <gtkmm/builder.h>
#include <glibmm/refptr.h>
#include <gtkmm/viewport.h>

#include <string>
#include <memory>

#include <view/interfaces/i_view_window.h>

#include <gtk_window.h>

namespace erebus {
class IGUIObject;
class IViewWindowPresenter;
class IView;
class GTK_ViewContainer;
}

namespace erebus {

class GTK_ViewWindow:public GTK_Window,public IViewWindow {
	std::unique_ptr<IViewWindowPresenter>	presenter_;

	Gtk::Viewport* 				base_;
	std::unique_ptr<GTK_ViewContainer>	basicViewContainer_;

	bool 					isInitialized_;
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

	void initialize(IGUIManager& manager);

	void addView(IView& view)override;

	/**
	 * See IViewWindow::classname
	 */
	virtual std::string classname()override;

	/**
	 * See IViewWindow::containsWidget
	 */
	bool containsWidget(std::size_t id)override;

	IGUIObject* getParentOf(std::size_t id)override;
};


}//namespace erebus

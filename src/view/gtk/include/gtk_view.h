#pragma once

#include <gtkmm.h>

#include <string>

#include <view/interfaces/i_view.h>
#include <presenter/interfaces/i_view_presenter.h>
#include <view/interfaces/i_view_container.h>

#include <gtk_view_container.h>

namespace erebus {

/**
 * This is the base class for every widget that can be added to the gui.
 * Every widget that derives from this class should at least have a constructor
 * that allows it to be created by a builder.
 */
class GTK_View:public Gtk::Viewport,virtual public IView {
	IViewPresenter*		presenter_;

	IViewContainer*	container_;

	std::string 		title_;

	int 			timeBuffer_;
	int			clickBuffer_;


	void init();

	void on_context_menu_pop_out_click();
	void on_context_menu_close_click();

  protected:
	/**
	 * The context menu to show.
	 */
	Gtk::Menu*	popupMenu_;

  public:
	/**
	 * Constructor.
	 *
	 * @param h_adjustment horizontal adjustment
	 * @param v_adjustment vertical adjustment
	 */
	GTK_View(Glib::RefPtr<Gtk::Adjustment> h_adjustment,Glib::RefPtr<Gtk::Adjustment> v_adjustment);

	/**
	 * Constructor.
	 *
	 * This contructor is needed to create this widget from a builder.
	 *
	 * When derived this constructor should be called and not the constructor
	 * of viewport. Otherwise import initilization cant be done.
	 *
	 * @param cobject used for creating this widget from a builder
	 * @param refBuilder used for created this widget from a builder
	 */
	GTK_View(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder);

	/**
	 * Copy constructor.
	 *
	 * Deleted until needed.
	 */
	GTK_View(const GTK_View &obj)=delete;

	/**
	 * Destructor.
	 */
	virtual ~GTK_View();

	/**
	 * See IView::setPresenter
	 *
	 * Needs to be called before every other method!
	 */
	virtual void setPresenter(IViewPresenter* presenter);

	/**
	 * See IView::setViewContainer
	 *
	 * Needs to be called before every other method!
	 */
	virtual void setParent(IViewContainer* container);

	/**
	 * See IView::close
	 */
	virtual void close();

	/**
	 * See IView::popOut
	 */
	virtual void popOut();

	/**
	 * See IView::setTitle
	 */
	virtual void setTitle(std::string title);

	/**
	 * See IView::getTitle
	 */
	virtual std::string getTitle();

	/**
	 * See IView::getViewContainer
	 */
	virtual IViewContainer* getParent();

	/**
	 * See IView::showContextMenu
	 */
	virtual void showContextMenu();


	/**
	 * Builds the custom context menu.
	 *
	 * This method should be overwritten by the derived class.
	 *
	 * In this method custom items can be added to the popup menu.
	 * In order to do so you have to call the super createContextMenu method first,
	 * e.g. GTK_View::createContextMenu.
	 *
	 * If you want to create a context menu like this:
	 * -------
	 * |Copy |
	 * -------
	 * |Paste|
	 * ------------------
	 * |standard entries|
	 * ------------------
	 *
	 * The methode should look like this:
	 *
	 * GTK_View::createContextMenu()
	 *
	 * popupMenu_->prepend(paste)
	 * popupMenu_->prepend(copy)
	 *
	 * popupMenu_->accelerate(*this)
	 * popupMenu_->show_all()
	 *
	 */
	virtual void createContextMenu();


	/**
	 * Gets called by a click on the view.
	 */
	bool on_button_press_event(GdkEventButton *ev);

	/**
	 * Gets called when the parent has changed (it was dragged)
	 */
	void on_my_parent_changed(Gtk::Widget* previous_parent);

};

}//namespace erebus
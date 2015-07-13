#pragma once

#include <gtkmm.h>

#include <string>

#include <view/interfaces/i_view.h>
#include <presenter/interfaces/i_presenter.h>
#include <presenter/interfaces/i_view_presenter.h>
#include <view/interfaces/i_view_container.h>

#include <gtk_view_container.h>

namespace erebus {

/**
 * This is the base class for every widget that can be added to the gui.
 * Every widget that derives from this class should at least have a constructor
 * that allows it to be created by a builder.
 */
class GTK_View:public Gtk::Viewport,public IView {
	IViewPresenter*		presenter_;

	GTK_ViewContainer*	container_;

	std::string 		title_;

	int 			timeBuffer_;
	int			clickBuffer_;


	void init();

	void sanityCheck();

  protected:
	/**
	 * The context menu to show.
	 *
	 * Doesnt need to be deleted by the derived class.
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
	void setPresenter(IPresenter* presenter) override;

	/**
	 * See IView::setViewContainer
	 *
	 * Needs to be called before every other method!
	 */
	void setViewContainer(IViewContainer* container) override;


	/**
	 * See IView::setTitle
	 */
	void setTitle(std::string title)override;

	/**
	 * See IView::getTitle
	 */
	std::string getTitle() override;

	/**
	 * See IView::showContextMenu
	 */
	void showContextMenu()override;


	/**
	 * Builds the custom context menu.
	 *
	 * This method should bew overwritten by the derived class.
	 * Only Gtk::MenuItems should be added. Noothing else.
	 * After that the createContextMenu from the super class
	 * should be called. It does the rest of the initilization.
	 */
	virtual void createContextMenu();


	/**
	 * Gets by a click on the view.
	 */
	bool on_button_press_event(GdkEventButton *ev) override;

};

}//namespace erebus
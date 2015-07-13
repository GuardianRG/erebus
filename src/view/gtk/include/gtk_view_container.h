#pragma once

#include <gtkmm.h>

#include <view/interfaces/i_view_container.h>
#include <presenter/interfaces/i_view_container_presenter.h>
#include <view/interfaces/i_view.h>

namespace erebus {

/**
 * This class containes the different views of the different areas on the screen.
 */
class GTK_ViewContainer:public IViewContainer,public Gtk::Viewport {
	Gtk::Notebook*	notebook_;
	Gtk::Paned*	paned_;

	IViewContainerPresenter* presenter_;

	Gtk::Menu* 	popupMenu_;

	Glib::RefPtr<Gtk::Adjustment> h_adjustment_;
	Glib::RefPtr<Gtk::Adjustment> v_adjustment_;

	int timeBuffer_;
	int clickBuffer_;

	void split();

	void on_context_menu_split_view_horizontal_click();
	void on_context_menu_split_view_vertical_click();
	void on_context_menu_add_view_empty_view_click();

  public:
	/**
	 * Constructor.
	 *
	 * @param h_adjustment horizontal adjustment for the child views.
	 * @param v_adjustment vertical adjustment for the child views.
	 */
	GTK_ViewContainer(Glib::RefPtr<Gtk::Adjustment> h_adjustment,Glib::RefPtr<Gtk::Adjustment> v_adjustment,Gtk::Notebook* notebook);

	/**
	 * Cop constructor.
	 *
	 * Deleted until needed.
	 */
	GTK_ViewContainer(const GTK_ViewContainer& obj)=delete;

	/**
	 * Destructor.
	 */
	~GTK_ViewContainer();

	/**
	 * See IViewContainer::setPresenter
	 */
	void setPresenter(IViewContainerPresenter* presenter)override;

	/**
	 * See IViewContainer::splitHorizontal
	 */
	void splitHorizontal() override;

	/**
	 * See IViewContainer::splitVertical
	 */
	void splitVertical() override;

	/**
	 * See IViewContainer::addView(IView* view)
	 */
	void addView(IView* view)override;

	/**
	 * See IViewContainer::addView(ViewType view)
	 */
	void addView(ViewType type)override;


	/**
	 * See IViewContainer::showTabs
	 */
	void showTabs(bool showTabs) override;

	/**
	 * See IViewContainer::showContextMenu
	 */

	void showContextMenu()override;

	/**
	 * See IViewContainer::isEmpty
	 */
	bool isEmpty()override;

	/**
	 * See IViewContainer::isTopLevel
	 */
	bool isTopLevel()override;

	/**
	 * Adds the standard menu items to the given menu.
	 *
	 * This method gets called by the widget this container contains.
	 * It adds the items like splitVertical, splitHorizontal ... to the menu.
	 *
	 * @param menu menu to add items to
	 */
	void buildContextMenu(Gtk::Menu* menu);

	/**
	 * Gets called when a mouseclick on this container occured.
	 */
	bool on_button_press_event(GdkEventButton *ev) override;

	/**
	 * Returns the horizontal adjustment.
	 *
	 * @return the horizontal adjustment
	 */
	Glib::RefPtr<Gtk::Adjustment> getHAdjustment();

	/**
	 * Returns the vertical adjustment.
	 *
	 * @return the vertical adjustment
	 */
	Glib::RefPtr<Gtk::Adjustment> getVAdjustment();
};
}//namespace erebus
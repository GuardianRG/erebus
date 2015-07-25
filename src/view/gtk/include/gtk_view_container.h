#pragma once

#include <gtkmm.h>

#include <memory>

#include <view/interfaces/i_view_container.h>
#include <presenter/interfaces/i_view_container_presenter.h>
#include <view/interfaces/i_view.h>

namespace erebus {

class GTK_View;

/**
 * This class containes the different views of the different areas on the
 * screen.
 */
class GTK_ViewContainer:public IViewContainer,public Gtk::Viewport {
	std::unique_ptr<Gtk::Notebook>			notebook_;
	Gtk::Paned*					paned_;

	std::unique_ptr<IViewContainerPresenter> 	presenter_;
	IViewContainer*					parent_;

	std::unique_ptr<Gtk::Menu>			popupMenu_;

	bool						isSplit_;

	int 						timeBuffer_;
	int 						clickBuffer_;

	void split();
	void sanityCheck();

	void on_context_menu_join_click();
	void on_context_menu_split_horizontal_click();
	void on_context_menu_split_vertical_click();
	void on_context_menu_add_view_empty_view_click();
	void on_context_menu_add_view_hex_view_click();

  public:
	/**
	 * Constructor.
	 *
	 * @param h_adjustment horizontal adjustment for the child views.
	 * @param v_adjustment vertical adjustment for the child views.
	 * @param notebook the notebook to use
	 * @param parent the parent view container
	 */
	GTK_ViewContainer(
	    Glib::RefPtr<Gtk::Adjustment> h_adjustment,
	    Glib::RefPtr<Gtk::Adjustment> v_adjustment,
	    std::unique_ptr<Gtk::Notebook> notebook,
	    IViewContainer* parent);

	/**
	 * Constructor.
	 *
	 * Creates an empty notebook.
	 *
	 * @param h_adjustment horizontal adjustment for the child views.
	 * @param v_adjustment vertical adjustment for the child views.
	 * @param parent the parent view container
	 */
	GTK_ViewContainer(
	    Glib::RefPtr<Gtk::Adjustment> h_adjustment,
	    Glib::RefPtr<Gtk::Adjustment> v_adjustment,
	    IViewContainer* parent);

	/**
	 * Copy constructor.
	 *
	 * Cant be copied since Gtk::Viewport cant be copied.
	 */
	GTK_ViewContainer(const GTK_ViewContainer &obj)=delete;

	/**
	 * Move Constructor.
	 *
	 * Cant be copied since Gtk::Viewport cant be copied.
	 */
	GTK_ViewContainer( GTK_ViewContainer&& )=delete;

	/**
	 * Copy assignment operator.
	 *
	 * Cant be copied since Gtk::Viewport cant be copied.
	 */
	GTK_ViewContainer& operator=(const GTK_ViewContainer&)=delete;

	/**
	 * Move assignment operator.
	 *
	 * Cant be copied since Gtk::Viewport cant be copied.
	 */
	GTK_ViewContainer& operator=(GTK_ViewContainer&&)=delete;

	/**
	 * Destructor.
	 */
	~GTK_ViewContainer();

	/**
	 * Sets the presenter.
	 */
	void setPresenter(std::unique_ptr<IViewContainerPresenter> presenter);

	/**
	 * See IViewContainer::getParent
	 */
	IViewContainer* getParent()const override;

	/**
	 * See IViewContainer::setParent
	 */
	void setParent(IViewContainer* parent)override;

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
	void addView(IView& view)override;

	/**
	 * See IViewContainer::addView(ViewType view)
	 */
	void addView(ViewType type)override;

	/**
	 * See IViewContainer::isSplittet
	 */
	bool isSplit()const override;

	/**
	 * See IViewContainer::showTabs
	 */
	void showTabs(bool showTabs) override;

	/**
	 * See IViewContainer::showContextMenu
	 */
	void showContextMenu()override;

	/**
	 * See IViewContainer::closeView
	 */
	void closeView(IView& view)override;

	/**
	 * See IViewContainer::joinContainer
	 */
	void joinContainer() override;

	/**
	 * See IViewContainer::isEmpty
	 */
	bool isEmpty(bool recursive)const override;

	/**
	 * See IViewContainer::popOutView
	 */
	void popOutView(IView& view)override;

	/**
	 * See IViewContainer::isTopLevel
	 */
	bool isTopLevel()const override;

	/**
	 * Removes the view.
	 *
	 * @param view the view to remove.
	 */
	void removeView(IView& view)override;

	/**
	 * Adds the standard menu items to the given menu.
	 *
	 * This method gets called by the widgets this container contains.
	 * It adds the items like splitVertical, splitHorizontal ... to the
	 * menu.
	 *
	 * @param menu menu to add items to
	 */
	void buildContextMenu(Gtk::Menu& menu);

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

#pragma once

#include <gtkmm/menu.h>
#include <glibmm/refptr.h>
#include <gtkmm/adjustment.h>
#include <gdk/gdk.h>
#include <gtkmm/paned.h>
#include <gtkmm/notebook.h>
#include <gtkmm/viewport.h>

#include <memory>

#include <view/interfaces/i_view_container.h>

namespace erebus {
class IViewContainerPresenter;
class IGUIManager;
class IGUIObject;
}

namespace erebus {

/**
 * This class containes the different views of the different areas on the
 * screen.
 */
class GTK_ViewContainer:public IViewContainer,public Gtk::Viewport {
	std::unique_ptr<IViewContainerPresenter> 	presenter_;
	IGUIManager*					guiManager_;

	std::unique_ptr<Gtk::Menu>			popupMenu_;
	std::unique_ptr<Gtk::Paned>			paned_;
	std::unique_ptr<GTK_ViewContainer>		child1_;
	std::unique_ptr<GTK_ViewContainer>		child2_;

	int 						timeBuffer_;
	int 						clickBuffer_;
	bool						isSplitted_;

	void buildContextMenu();

	bool on_button_press_event(GdkEventButton *ev) override;



	//std::unique_ptr<Gtk::Notebook>			notebook_;

	//



	void split();
	//void sanityCheck();

	void on_context_menu_join_click();
	void on_context_menu_split_horizontal_click();
	void on_context_menu_split_vertical_click();
	//void on_context_menu_add_view_empty_view_click();
	//void on_context_menu_add_view_hex_view_click();

  public:
	static const std::string CLASSNAME;
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
	    std::unique_ptr<Gtk::Notebook> notebook);

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
	 * See IViewContainer::setGUIManager
	 */
	void setGUIManager(IGUIManager& manager)override;

	/**
	 * See IViewContainer::getGUIManager
	 */
	IGUIManager& getGUIManager()override;

	/**
	 * See IViewContainer::getID
	 */
	std::size_t getID()override;

	/**
	 * See IViewContainer::getParentOf
	 */
	IGUIObject* getParentOf(std::size_t id)override;

	/**
	 * See IViewContainer::containsWidget
	 */
	bool containsWidget(std::size_t id)override;

	/**
	 * See IViewContainer::classname
	 */
	std::string classname()override;

	/**
	 * Sets the presenter.
	 */
	void setPresenter(std::unique_ptr<IViewContainerPresenter> presenter);

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
	//void addView(IView& view)override;

	/**
	 * See IViewContainer::addView(ViewType view)
	 */
	//void addView(ViewType type)override;

	/**
	 * See IViewContainer::isSplitted
	 */
	bool isSplitted()const override;

	/**
	 * See IViewContainer::showTabs
	 */
	//void showTabs(bool showTabs) override;

	/**
	 * See IViewContainer::showContextMenu
	 */
	void showContextMenu()override;

	/**
	 * See IViewContainer::closeView
	 */
	//void closeView(IView& view)override;

	/**
	 * See IViewContainer::join
	 */
	void join() override;

	/**
	 * See IViewContainer::isEmpty
	 */
	//bool isEmpty(bool recursive)const override;

	/**
	 * See IViewContainer::popOutView
	 */
	//void popOutView(IView& view)override;

	/**
	 * See IViewContainer::isTopLevel
	 */
	bool isTopLevel()const override;

	/**
	 * Removes the view.
	 *
	 * @param view the view to remove.
	 */
	//void removeView(IView& view)override;

	/**
	 * Gets called when a mouseclick on this container occured.
	 */

};
}//namespace erebus

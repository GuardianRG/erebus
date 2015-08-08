#pragma once

#include <gtkmm/menu.h>
#include <glibmm/refptr.h>
#include <gtkmm/adjustment.h>
#include <gdk/gdk.h>
#include <gtkmm/paned.h>
#include <gtkmm/menuitem.h>
#include <gtkmm/notebook.h>
#include <gtkmm/viewport.h>
#include <gtkmm/separatormenuitem.h>

#include <memory>

#include <i_view_container.h>
#include <view_type.h>

namespace erebus {

class IViewContainerPresenter;
class IGUIManager;
class IGUIObject;
class GTK_View;
class IView;

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
	std::unique_ptr<Gtk::MenuItem>			joinItem_;
	std::unique_ptr<Gtk::MenuItem>			viewItem_;
	std::unique_ptr<Gtk::SeparatorMenuItem>		separator_;
	std::unique_ptr<Gtk::SeparatorMenuItem>		separator1_;
	std::unique_ptr<Gtk::Notebook>			notebook_;

	int 						timeBuffer_;
	int 						clickBuffer_;
	bool						isSplitted_;

	void buildContextMenu();
	void updateContextMenu();

	bool on_button_press_event(GdkEventButton *ev) override;

	void addViewPr(GTK_View& view);
	void split();

	void on_context_menu_close_click();
	void on_context_menu_pop_out_click();
	void on_context_menu_join_click();
	void on_context_menu_split_horizontal_click();
	void on_context_menu_split_vertical_click();
	void on_context_menu_add_empty_view_click();
	void on_context_menu_add_hex_view_click();

  public:
	/**
	 * The classname that is returned by GTK_ViewContainer::classname.
	 */
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
	    std::unique_ptr<Gtk::Notebook> notebook,IGUIManager& manager);

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
	 * See IViewContainer::setGUIManager.
	 */
	void setGUIManager(IGUIManager& manager)override;

	/**
	 * See IViewContainer::getGUIManager.
	 */
	IGUIManager& getGUIManager()override;

	/**
	 * See IViewContainer::getID.
	 */
	std::size_t getID()override;

	/**
	 * See IViewContainer::getParentOf.
	 */
	IGUIObject* getParentOf(std::size_t id)override;

	/**
	 * See IViewContainer::getActiveView.
	 */
	IView* getActiveView()override;

	/**
	 * See IViewContainer::removeView.
	 */
	void removeView(IView& view)override;

	/**
	 * See IViewContainer::containsWidget.
	 */
	bool containsWidget(std::size_t id)override;

	/**
	 * See IViewContainer::classname.
	 */
	std::string classname()override;

	/**
	 * Sets the presenter.
	 *
	 * @param presenter the presenter to set
	 */
	void setPresenter(std::unique_ptr<IViewContainerPresenter> presenter);

	/**
	 * See IViewContainer::splitHorizontal.
	 */
	void splitHorizontal() override;

	/**
	 * See IViewContainer::splitVertical.
	 */
	void splitVertical() override;

	/**
	 * See IViewContainer::closeActiveView.
	 */
	void closeActiveView()override;

	/**
	 * See IViewContainer::addView(IView view).
	 */
	void addView(IView& view)override;

	/**
	 * See IViewContainer::addView(ViewType view).
	 */
	void addView(ViewType type)override;

	/**
	 * See IViewContainer::isSplitted.
	 */
	bool isSplitted()const override;

	/**
	 * See IViewContainer::closeView.
	 */
	void closeView(IView& view)override;

	/**
	 * See IViewContainer::showContextMenu.
	 */
	void showContextMenu()override;

	/**
	 * See IViewContainer::join.
	 */
	void join() override;

	/**
	 * See IViewContainer::isTopLevel.
	 */
	bool isTopLevel()const override;

};

}//namespace erebus

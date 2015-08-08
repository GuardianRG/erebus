#pragma once

#include <gtkmm/builder.h>
#include <glibmm/refptr.h>
#include <gtkmm/viewport.h>
#include <gtkmm/menu.h>

#include <string>

#include <i_view.h>

namespace erebus {

class IGUIManager;

}

namespace erebus {

/**
 * This is the base class for every widget that can be added to the gui.
 * Every widget that derives from this class should at least have a constructor
 * that allows it to be created by a builder.
 */
class GTK_View:public Gtk::Viewport,virtual public IView {
	std::string 			title_;

  protected:
	IGUIManager*	guiManager_;

  public:
	/**
	 * Constructor.
	 *
	 * This contructor is needed to create this widget from a builder.
	 *
	 * When derived this constructor should be called and not the constructor
	 * of viewport.
	 *
	 * @param cobject used for creating this widget from a builder
	 * @param refBuilder used for created this widget from a builder
	 */
	GTK_View(BaseObjectType* cobject);

	/**
	 * Copy constructor.
	 *
	 * Cant be copied since Gtk::Viewport cant be copied.
	 */
	GTK_View(const GTK_View &obj)=delete;

	/**
	 * Move Constructor.
	 *
	 * Cant be copied since Gtk::Viewport cant be copied.
	 */
	GTK_View( GTK_View&& )=delete;

	/**
	 * Copy assignment operator.
	 *
	 * Cant be copied since Gtk::Viewport cant be copied.
	 */
	GTK_View& operator=(const GTK_View&)=delete;

	/**
	 * Move assignment operator.
	 *
	 * Cant be copied since Gtk::Viewport cant be copied.
	 */
	GTK_View& operator=(GTK_View&&)=delete;


	/**
	 * Destructor.
	 */
	virtual ~GTK_View();

	/**
	 * Creates a context menu and returns it.
	 *
	 * The created context menu gets shown by the container that this view is contained in.
	 * This method should be overwritten.
	 *
	 * @return the context menu
	 */
	virtual std::unique_ptr<Gtk::Menu> createContextMenu();

	/**
	 * See IView::setGUIManager.
	 */
	void setGUIManager(IGUIManager& manager)override;

	/**
	 * See IView::getGUIManager.
	 */
	IGUIManager& getGUIManager()override;

	/**
	 * See IView::setTitle
	 */
	void setTitle(const std::string& title) override;

	/**
	 * See IView::getTitle
	 */
	std::string getTitle() const override;

};

}//namespace erebus

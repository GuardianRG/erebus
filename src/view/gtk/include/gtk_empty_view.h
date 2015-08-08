#pragma once

#include <gtkmm/builder.h>
#include <glibmm/refptr.h>

#include <memory>

#include <i_empty_view.h>
#include <gtk_view.h>

namespace erebus {

enum class ViewType;
class IEmptyViewPresenter;

}


namespace erebus {

/**
 * This class is a empty view.
 *
 * This view does nothing except of being a prove of concept.
 * Kind of a dummy.
 *
 */
class GTK_EmptyView:public GTK_View,public IEmptyView  {
	std::unique_ptr<IEmptyViewPresenter>	presenter_;

  public:
	/**
	 * The classname that gets returned by GTK_EmptyView::classname.
	 */
	static const std::string CLASSNAME;

	/**
	 * Constructor.
	 *
	 * This constructor is needed to create a view from file.
	 */
	GTK_EmptyView(BaseObjectType* cobject,
	              const Glib::RefPtr<Gtk::Builder>& refBuilder);

	/**
	 * Copy constructor.
	 *
	 * Cant be copied since Gtk::Viewport cant be copied.
	 */
	GTK_EmptyView(const GTK_EmptyView &obj)=delete;

	/**
	 * Move Constructor.
	 *
	 * Cant be moved since Gtk::Viewport cant be moved.
	 */
	GTK_EmptyView( GTK_EmptyView&& )=delete;

	/**
	 * Copy assignment operator.
	 *
	 * Cant be copied since Gtk::Viewport cant be copied.
	 */
	GTK_EmptyView& operator=(const GTK_EmptyView&)=delete;

	/**
	 * Move assignment operator.
	 *
	 * Cant be moved since Gtk::Viewport cant be moved.
	 */
	GTK_EmptyView& operator=(GTK_EmptyView&&)=delete;

	/**
	 * Destructor.
	 */
	~GTK_EmptyView();


	/**
	 * Sets the presenter.
	 *
	 * @param presenter the presenter of this view.
	 */
	void setPresenter(std::unique_ptr<IEmptyViewPresenter> presenter);

	/**
	 * See IEmptyView::classname.
	 */
	std::string classname()override;

	/**
	 * See IEmptyView::classname.
	 */
	std::size_t getID()override;

};

}//namespace erebus

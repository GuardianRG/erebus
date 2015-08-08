#pragma once

#include <gtkmm/builder.h>
#include <glibmm/refptr.h>

#include <string>

#include <i_hex_view.h>
#include <gtk_view.h>

namespace erebus {

enum class ViewType;
class IHexViewPresenter;

}

namespace erebus {
class GTK_HexView:public GTK_View,public IHexView {
	std::unique_ptr<IHexViewPresenter>	presenter_;

  public:
	/**
	 * The classname that is returnded by GTK_HexView::classname.
	 */
	static const std::string CLASSNAME;

	GTK_HexView(BaseObjectType* cobject,
	            const Glib::RefPtr<Gtk::Builder>& refBuilder);

	/**
	 * Copy constructor.
	 *
	 * Cant be copied since Gtk::Viewport cant be copied.
	 */
	GTK_HexView(const GTK_HexView &obj)=delete;

	/**
	 * Move Constructor.
	 *
	 * Cant be moved since Gtk::Viewport cant be moved.
	 */
	GTK_HexView( GTK_HexView&& )=delete;

	/**
	 * Copy assignment operator.
	 *
	 * Cant be copied since Gtk::Viewport cant be copied.
	 */
	GTK_HexView& operator=(const GTK_HexView&)=delete;

	/**
	 * Move assignment operator.
	 *
	 * Cant be moved since Gtk::Viewport cant be moved.
	 */
	GTK_HexView& operator=(GTK_HexView&&)=delete;

	/**
	 * Destructor.
	 */
	~GTK_HexView();


	/**
	 * See IHexView::setPresenter.
	 */
	void setPresenter(std::unique_ptr<IHexViewPresenter> presenter);

	/**
	 * See IHexView::classname.
	 */
	std::string classname()override;

	/**
	 * See IHexView::classname.
	 */
	std::size_t getID()override;

};

}//namespace erebus

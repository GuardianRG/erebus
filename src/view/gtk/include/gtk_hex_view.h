#pragma once

#include <presenter/interfaces/i_hex_view_presenter.h>
#include <presenter/interfaces/i_view_presenter.h>
#include <view/interfaces/i_hex_view.h>

#include <gtk_view.h>

namespace erebus {
class GTK_HexView:public GTK_View,public IHexView {
	std::unique_ptr<IHexViewPresenter>	presenter_;
  protected:
	IViewPresenter& getPresenter() const override;
  public:
	GTK_HexView(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder);

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

	void createContextMenu()override;
	/**
	 * See IHexView::setPresenter
	 */
	void setPresenter(std::unique_ptr<IHexViewPresenter> presenter);

	/**
	 * See IHexView::getTitle
	 */
	std::string getTitle()const override;

	/**
	 * See IHexView::setTitle
	 */
	void setTitle(std::string title)override;

	/**
	 * See IHexView::showContextMenu
	 */
	void showContextMenu()override;

	/**
	 * See IHexView::close
	 */
	void close()override;
	
	

	/**
	 * See IHexView::setParent
	 */
	void setParent(IViewContainer* container)override;

	/**
	 * See IHexView::getParent
	 */
	IViewContainer* getParent()const override;

	/**
	 * See IHexView::popOut
	 */
	void popOut()override;
};
}//namespace erebus

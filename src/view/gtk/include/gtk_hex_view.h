#pragma once

#include <presenter/interfaces/i_hex_view_presenter.h>
#include <presenter/interfaces/i_view_presenter.h>
#include <view/interfaces/i_hex_view.h>

#include <gtk_view.h>

namespace erebus {
class GTK_HexView:public GTK_View,public IHexView {
	IHexViewPresenter*	presenter_;
  public:
	GTK_HexView(Glib::RefPtr<Gtk::Adjustment> h_adjustment,Glib::RefPtr<Gtk::Adjustment> v_adjustment);

	GTK_HexView(const GTK_HexView &obj)=delete;

	~GTK_HexView();

	void createContextMenu()override;
	/**
	 * See IHexView::setPresenter
	 */
	void setPresenter(IViewPresenter* presenter)override;

	/**
	 * See IHexView::getTitle
	 */
	std::string getTitle()override;

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
	IViewContainer* getParent()override;

	/**
	 * See IHexView::popOut
	 */
	void popOut()override;
};
}//namespace erebus

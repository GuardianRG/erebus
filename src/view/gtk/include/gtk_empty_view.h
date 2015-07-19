#pragma once
#pragma once

#include <gtkmm.h>

#include <presenter/interfaces/i_empty_view_presenter.h>
#include <presenter/interfaces/i_view_presenter.h>
#include <view/interfaces/i_empty_view.h>

#include <gtk_view.h>


namespace erebus {

/**
 * This class is a empty view.
 *
 * This view does nothing except of being a prove of concept.
 * Kind of a dummy.
 *
 * See GTK_View
 */
class GTK_EmptyView:public GTK_View,public IEmptyView  {
	IEmptyViewPresenter*	presenter_;
  public:
	/**
	 * Constructor.
	 *
	 * This constructor is needed to create a valid View.
	 */
	GTK_EmptyView(Glib::RefPtr<Gtk::Adjustment> h_adjustment,Glib::RefPtr<Gtk::Adjustment> v_adjustment);

	/**
	 * Copy constructor.
	 *
	 * Deleted until needed.
	 */
	GTK_EmptyView(const GTK_EmptyView &obj)=delete;

	/**
	 * Destructor.
	 */
	~GTK_EmptyView();


	void createContextMenu() override;

	/**
	 * See IEmptyView::setPresenter
	 */
	void setPresenter(IViewPresenter* presenter)override;

	/**
	 * See IEmptyView::getTitle
	 */
	std::string getTitle()override;

	/**
	 * See IEmptyView::setTitle
	 */
	void setTitle(std::string title)override;

	/**
	 * See IEmptyView::showContextMenu
	 */
	void showContextMenu()override;

	/**
	 * See IEmptyView::close
	 */
	void close()override;

	/**
	 * See IEmptyView::setParent
	 */
	void setParent(IViewContainer* container)override;

	/**
	 * See IEmptyView::getParent
	 */
	IViewContainer* getParent()override;

	/**
	 * See IEmptyView::popOut
	 */
	void popOut()override;


};

}//namespace erebus
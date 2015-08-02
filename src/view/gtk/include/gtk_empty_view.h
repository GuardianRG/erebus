#pragma once

#include <gtkmm.h>

#include <memory>

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
	std::unique_ptr<IEmptyViewPresenter>	presenter_;

  protected:
	IViewPresenter& getPresenter() const override;

  public:
	/**
	 * Constructor.
	 *
	 * This constructor is needed to create a valid View.
	 */
	GTK_EmptyView(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder);

	/**
	 * Copy constructor.
	 *
	 * Cant be copied since Gtk::Viewport cant be copied-
	 */
	GTK_EmptyView(const GTK_EmptyView &obj)=delete;

	/**
	 * Move Constructor.
	 *
	 * Cant be copied since Gtk::Viewport cant be copied-
	 */
	GTK_EmptyView( GTK_EmptyView&& )=delete;

	/**
	 * Copy assignment operator.
	 *
	 * Cant be copied since Gtk::Viewport cant be copied-
	 */
	GTK_EmptyView& operator=(const GTK_EmptyView&)=delete;

	/**
	 * Move assignment operator.
	 *
	 * Cant be copied since Gtk::Viewport cant be copied-
	 */
	GTK_EmptyView& operator=(GTK_EmptyView&&)=delete;

	/**
	 * Destructor.
	 */
	~GTK_EmptyView();
	
	
	/**
	 * See GTK_View::createContextMenu
	 */
	void createContextMenu() override;

	/**
	 * Sets the presenter.
	 *
	 * @param presenter the presenter of this view.
	 */
	void setPresenter(std::unique_ptr<IEmptyViewPresenter> presenter);

	/**
	 * See IEmptyView::getTitle
	 */
	std::string getTitle()const override;

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
	IViewContainer* getParent() const override;

	/**
	 * See IEmptyView::popOut
	 */
	void popOut()override;


};

}//namespace erebus

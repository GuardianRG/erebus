#pragma once

#include <string>

#include <gtkmm.h>

#include <interfaces/i_main_view.h>
#include <interfaces/i_presenter.h>
#include <interfaces/i_main_view_presenter.h>

namespace erebus {

/**
 * A concrete view.
 */
class GtkMainView : public Gtk::Window,public IMainView {
	IMainViewPresenter* presenter_;

	Gtk::ImageMenuItem* menu_file_open_;

	void on_menu_file_open_click();

  public:
	/**
	 * Constructor.
	 *
	 * This contructor has these arguments so it can be build by a Gtk::Builder.
	 */
	GtkMainView(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder);

	/**
	 * Copy Constructor.
	 */
	GtkMainView(const GtkMainView &obj)=delete;

	/**
	 * Destructor.
	 */
	~GtkMainView();


	/**
	 * See IMainView::setPresenter(IPresenter* presenter).
	 */
	void setPresenter(IPresenter* presenter) override;

	/**
	 * See IMainView::setPreferredSize(int width,int height).
	 */
	void setPreferredSize(int width,int height) override;

	/**
	 * See IMainView::setTitle(std::string title).
	 */
	void setTitle(std::string title) override;

	/**
	 * See IMainView::maximize().
	 */
	void maximize() override;

	/**
	 * See IMainView::unmaximize().
	 */
	void unmaximize() override;

	/**
	 * See IMainView::showErrorMessage(std::string errorMsg).
	 */
	void showErrorMessage(std::string errorMsg);
};

}
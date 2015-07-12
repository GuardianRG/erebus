#pragma once

#include <gtkmm.h>

#include <presenter/interfaces/i_main_window_presenter.h>
#include <presenter/interfaces/i_presenter.h>
#include <gtk_view.h>

#include <view/interfaces/i_main_window.h>
#include <gtk_view_container.h>

namespace erebus {

class GTK_MainWindow : public Gtk::Window, public IMainWindow {
	IMainWindowPresenter*	presenter_;


	GTK_ViewContainer*	basicView_;

  public:
	GTK_MainWindow();

	GTK_MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder);

	GTK_MainWindow(const GTK_MainWindow &obj)=delete;

	~GTK_MainWindow();



	void setPresenter(IPresenter* presenter) override;

	void setTitle(std::string title) override;
	void setPreferredSize(int width,int height) override;
	void maximize() override;
	void unmaximize() override;
};
}
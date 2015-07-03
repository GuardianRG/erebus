#pragma once

#include <string>

#include <gtkmm.h>

#include <interfaces/i_main_view.h>
#include <interfaces/i_presenter.h>
#include <interfaces/i_main_view_presenter.h>

namespace erebus {

class MainView : public Gtk::Window,public IMainView {
	IMainViewPresenter* presenter_;
	
	Gtk::ImageMenuItem* menu_file_open_;
	
	void on_menu_file_open_click();

public:
	MainView(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder);
	~MainView();
	
	void setPresenter(IPresenter* presenter) override;
	void setPreferredSize(int width,int height) override;
	void setTitle(std::string title) override;
	void maximize() override;
	void unmaximize() override;
};

}
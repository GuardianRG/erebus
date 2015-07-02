#pragma once

#include <string>
#include <boost/signals2.hpp>
#include <boost/function.hpp>

#include <gtkmm.h>

#include <interfaces/i_main_view.h>

namespace erebus {

class MainView : public Gtk::Window,public IMainView {

public:
	MainView(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder);
	~MainView();

	void setPreferredSize(int width,int height) override;
	void setTitle(std::string title) override;
	
	void registerFunctionQuit(boost::function<void()> func) override;

protected:


	void on_menu_file_open();
	void on_menu_file_quit();

private:
	boost::signals2::signal<void()> quit_;
	
	void initFrame();


};

}
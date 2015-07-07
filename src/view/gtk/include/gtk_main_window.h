#pragma once

#include <gtkmm.h>

#include <view/interfaces/i_main_window.h>

namespace erebus {
	
	class GTK_MainWindow : public Gtk::Window, public IMainWindow {
public:
	GTK_MainWindow();
	
	GTK_MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder);
	
	GTK_MainWindow(const GTK_MainWindow &obj)=delete;
	
	~GTK_MainWindow();
	
	void setTitle(std::string title) override;
	void setPreferredSize(int width,int height) override;
	void maximize() override;
	void unmaximize() override;
};
}
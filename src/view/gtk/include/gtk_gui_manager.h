#pragma once

#include <gtkmm/application.h>

#include <string>
#include <vector>
#include <memory>

#include <view/interfaces/i_gui_manager.h>
#include <view/interfaces/i_window.h>

namespace erebus {
class GTK_GUIManager:public IGUIManager {
	Glib::RefPtr<Gtk::Application> 		application_;

	std::vector<std::unique_ptr<IWindow>>	windows_;

	bool	 				isInitialized_;

  public:
	static const std::string PACKAGE_NAME;

	GTK_GUIManager();
	~GTK_GUIManager();

	void initialize(int argc,char** argv);

	void showMessageDialog(std::string primaryText,std::string secondaryText,
	                       ErrorLevel errorLevel)override;

	void runGUI()override;

};
}//namespace erebus
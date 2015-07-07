#pragma once

#include <view/interfaces/i_main_window.h>
#include <view/interfaces/i_gui_state_object.h>


namespace erebus {

class GUIManager {
	int&		argc_;
	char**& 	argv_;
	
	IMainWindow	*mainWindow_;
	
	IGUIStateObject	*stateObject_;
	
public:
	GUIManager(int& argc, char**& argv);
	
	GUIManager(const GUIManager &obj)=delete;
	
	~GUIManager();
	
	
	void runGUI();
};

}
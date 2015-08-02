#include <view/view_preferences_saver.h>

#include <iostream>
#include <fstream>

#include <view/view_preferences.h>
#include <logger.h>
#include <file_system.h>
#include <types.h>

INIT_LOCATION;

namespace erebus {
ViewPreferencesSaver::ViewPreferencesSaver() {
	if(!doesFileExist(ViewPreferences::VIEW_PREFERENCE_FILE)) {
		createFile(ViewPreferences::VIEW_PREFERENCE_FILE);
		BOOST_LOG_SEV(main_l::get(),warning)<<LOCATION
		                                    <<"Created '"
		                                    <<ViewPreferences::VIEW_PREFERENCE_FILE
		                                    <<"'";
	}
	preferenceFile_= new std::ofstream(ViewPreferences::VIEW_PREFERENCE_FILE);
}

ViewPreferencesSaver::ViewPreferencesSaver( ViewPreferencesSaver&& obj): preferenceFile_(obj.preferenceFile_) {

}

ViewPreferencesSaver& ViewPreferencesSaver::operator=(ViewPreferencesSaver&& obj) {
	if(this != &obj) {
		preferenceFile_=obj.preferenceFile_;
	}
	return *this;
}


ViewPreferencesSaver::~ViewPreferencesSaver() {
	preferenceFile_->close();
	delete preferenceFile_;
}

void ViewPreferencesSaver::saveViewPreferences() {
	//using vp=ViewPreferences;

	BOOST_LOG_SEV(main_l::get(),normal)<<LOCATION<<"Saving view preferences";

	//writeToFile(vp::ALWAYS_SHOW_TABS,BoolStr::toStr(vpo.getAlwaysShowTabs()));


}

void ViewPreferencesSaver::writeToFile(std::string pref,std::string val) {
	*preferenceFile_<<pref<<"="<<val<<std::endl;
}

}//namespace erebus

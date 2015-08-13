#pragma once

#include <unordered_map>
#include <memory>
#include <vector>
#include <string>

#include <no_such_element.h>
#include <view_preference.h>

namespace erebus {

	
class ViewPreferencesManager {
	std::unordered_map<std::string,std::unique_ptr<ViewPreference>>	preferences_;
	
	ViewPreference* insertDefaultViewPreference(const std::string& key);
	ViewPreference* getPreferencePr(const std::string& key);

  public:
	  static const std::string CUSTOM_VIEW_PREFERENCES_FILE;
	  static const std::string DEFAULT_VIEW_PREFERENCES_FILE;
	  
	  ViewPreferencesManager();
	  ~ViewPreferencesManager();
	  
	  ViewPreferencesManager(const ViewPreferencesManager&)=delete;
	  
	  ViewPreferencesManager(ViewPreferencesManager&&)=delete;
	  
	  ViewPreferencesManager& operator=(const ViewPreferencesManager&)=delete;
	  
	  ViewPreferencesManager& operator=(ViewPreferencesManager&&)=delete;
	  
	  std::string getPreference(const std::string& key);
	  void setPreference(const std::string& key,const std::string& value);
	  
	  decltype(preferences_.begin()) begin() {
		return preferences_.begin();  
	  }
	  decltype(preferences_.end()) end() {
		return preferences_.end();  
	  }
	  
	  bool getPreferenceBool(const std::string& key);
	  void setPreferenceBool(const std::string&key, bool value);
};

}//namespace erebus

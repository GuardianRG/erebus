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
	  
	  bool getBooleanPreference(const std::string& key);
	  void setBooleanPreference(const std::string&key, bool value);
};

}//namespace erebus

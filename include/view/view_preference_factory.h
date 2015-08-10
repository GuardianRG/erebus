#pragma once

#include <vector>
#include <string>
#include <memory>

#include <view_preference.h>

namespace erebus {
	class ViewPreferenceFactory {
		static std::vector<std::string>	validKeys_;
		
		ViewPreferenceFactory();
	public:
		static const std::string INVALID_KEY;
		~ViewPreferenceFactory();
		static bool isKeyValid(const std::string& key);
		
		static std::unique_ptr<ViewPreference> createViewPreference(const std::string& key, const std::string& value);
		
		static std::unique_ptr<ViewPreference> createViewPreference(const std::string& key);
	
};
}//namespace erebus
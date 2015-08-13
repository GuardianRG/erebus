#pragma once

#include <vector>
#include <string>
#include <memory>

#include <view_preference.h>

namespace erebus {
	class ViewPreferenceFactory {
		static std::vector<std::string>	validKeys_;
		
		template<typename T>
		typename std::enable_if<std::is_base_of<ViewPreference, T>::value,std::unique_ptr<T>>::type
		static createViewPreferencePr(const std::string& key, const std::string& value) {
			if(value!=INVALID_VALUE) {
				return std::make_unique<T>(value);
			}
			return std::make_unique<T>();
		}
		
		ViewPreferenceFactory();
	public:
		static const std::string INVALID_VALUE;
		~ViewPreferenceFactory();
		
		static bool isKeyValid(const std::string& key);
		
		static std::unique_ptr<ViewPreference> createViewPreference(const std::string& key, const std::string& value);
		
		static std::unique_ptr<ViewPreference> createViewPreference(const std::string& key);
	
};
}//namespace erebus
#include <view_preference_factory.h>

#include <string>
#include <memory>

#include <view_preference.h>
#include <no_such_element.h>
#include <allow_multiple_application_instances_pref.h>
#include <logger.h>

INIT_LOCATION;

namespace erebus {
	const std::string ViewPreferenceFactory::INVALID_KEY="--no_value--";
	
	std::vector<std::string> ViewPreferenceFactory::validKeys_;/*= {
			AllowMultipleApplicationInstancesPref::KEY
	};*/
	
	ViewPreferenceFactory::ViewPreferenceFactory() {
		
	}
	
	ViewPreferenceFactory::~ViewPreferenceFactory() {
		
	}
	
	bool ViewPreferenceFactory::isKeyValid(const std::string& key) {
		return (std::find(validKeys_.begin(), validKeys_.end(), key)!=validKeys_.end() );
	}
	
	std::unique_ptr<ViewPreference> ViewPreferenceFactory::createViewPreference(const std::string& key)  {
		return createViewPreference(key,"--no_value--");
	}
	
	std::unique_ptr<ViewPreference> ViewPreferenceFactory::createViewPreference(const std::string& key, const std::string& value) {
		if(!isKeyValid(key)) {
			throw no_such_element(std::string("'")+key+"' is not a valid key");
		}
		
		if(key==AllowMultipleApplicationInstancesPref::KEY) {
			if(value!="--no_value--") {
			return std::make_unique<AllowMultipleApplicationInstancesPref>(value);
			}
			return std::make_unique<AllowMultipleApplicationInstancesPref>();
		}
		else {
			LOG_ASSERT_MAIN(false);
		}
		return nullptr;
	}

}//namespace erebus
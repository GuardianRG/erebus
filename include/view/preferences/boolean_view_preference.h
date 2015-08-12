#pragma once

#include <string>

#include <view_preference.h>

namespace erebus {
	class BooleanViewPreference:public ViewPreference {
	protected:
		bool isValueValid(const std::string& value)override;
	public:
		static const std::string STRUE;
		static const std::string SFALSE;
		
		static std::string boolToStr(bool value);
		
		static bool strToBool(const std::string& value);
		
		using ViewPreference::setValue;
		
		BooleanViewPreference(const std::string& value);
		BooleanViewPreference(bool value);
		~BooleanViewPreference();
		
		void setValue(bool value);
		
		bool getValueBool();
		
	};

}//namespace erebus
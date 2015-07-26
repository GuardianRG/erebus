#include <types.h>

#include <string>
#include <typeinfo>

std::string const BoolStr::STRUE="true";
std::string const BoolStr::SFALSE="false";

bool BoolStr::toBool(std::string str) {
	if(str==BoolStr::STRUE) {
		return true;
	} else if(str==BoolStr::SFALSE) {
		return false;
	}

	throw std::bad_cast{};
}

std::string BoolStr::toStr(bool b) {
	if(b) {
		return BoolStr::STRUE;
	}
	return BoolStr::SFALSE;
}

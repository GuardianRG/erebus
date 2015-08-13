#include <close_empty_view_windows_pref.h>

#include <string>

#include <boolean_view_preference.h>

namespace erebus {
const std::string CloseEmptyViewWindowsPref::KEY="close_empty_view_windows";

const bool CloseEmptyViewWindowsPref::DEFAULT_VALUE=true;

CloseEmptyViewWindowsPref::CloseEmptyViewWindowsPref(const std::string& value):
	BooleanViewPreference(value) {

}

CloseEmptyViewWindowsPref::CloseEmptyViewWindowsPref(bool value):BooleanViewPreference(value) {

}

CloseEmptyViewWindowsPref::CloseEmptyViewWindowsPref():BooleanViewPreference(getDefaultValue()) {

}

CloseEmptyViewWindowsPref::~CloseEmptyViewWindowsPref() {

}

std::string CloseEmptyViewWindowsPref::getKey() {
	return KEY;
}

std::string CloseEmptyViewWindowsPref::getDefaultValue() {
	return BooleanViewPreference::boolToStr(DEFAULT_VALUE);
}
}//namespace erebus

#include <logger.h>

#include <string>
#include <boost/filesystem/path.hpp>

std::ostream& operator<< (std::ostream& strm, severity_level level) {
	static const char* strings[] = {
		"normal",
		"notification",
		"warning",
		"error",
		"critical"
	};

	if (static_cast< std::size_t >(level) < sizeof(strings) / sizeof(*strings))
		strm << strings[level];
	else
		strm << static_cast< int >(level);

	return strm;
}

std::string getDisplayPath(const std::string& path) {
	boost::filesystem::path bpath{path};
	auto it=bpath.begin();
	std::string displayPath("");
	for(auto end=--bpath.end();end!=bpath.begin();--end) {
		auto s=(*end).filename().string();
		if(s!="erebus") {
			displayPath.insert(0,s);
			displayPath.insert(0,"/");
		}
		else {
			displayPath.insert(0,s);
			break;
		}
	}
	return displayPath;
}
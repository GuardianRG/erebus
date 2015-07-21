#include <logger.h>

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

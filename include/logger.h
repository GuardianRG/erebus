#pragma once

#include <boost/log/sources/severity_channel_logger.hpp>
#include <boost/log/sources/global_logger_storage.hpp>
#include <boost/log/trivial.hpp>

//Should be used in the log messages
#define LOCATION "("<<__FILE__<<" : "<<__LINE__<<")->"

//The different serevrity levels
enum severity_level {
	normal,
	notification,
	warning,
	error,
	critical
};

using severity_channel_logger = boost::log::sources::severity_channel_logger_mt<severity_level,std::string>;

//Forward declaration
std::ostream& operator<< (std::ostream& strm, severity_level level);

//Init the global logger for the main channel
BOOST_LOG_INLINE_GLOBAL_LOGGER_INIT(main_l, severity_channel_logger) {
	return severity_channel_logger(boost::log::keywords::channel = "MAIN");
}

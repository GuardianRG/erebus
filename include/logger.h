#pragma once

#include <string>
#include <iostream>

#include <boost/log/sources/severity_channel_logger.hpp>
#include <boost/log/sources/global_logger_storage.hpp>
#include <boost/log/trivial.hpp>

#include <assert.h>

//This macro is the location of this statement as string
#define LOCATION_ALL (std::string("(")+displayPath+" : "+std::to_string(__LINE__)+") ")

//If you want to use LOCATION in your log messages then you have to call
//this INIT_LOCATION in your file even before opening the namespace.
//If you dont the code wont compile.
#define INIT_LOCATION namespace {std::string displayPath=getDisplayPath(std::string(__FILE__));}

//Should be used in the log messages
#ifdef _DEBUG_

//This macro defines a string which holds the location of the occurence of LOCATION
#define LOCATION LOCATION_ALL

#else
#define LOCATION ""
#endif

//defines a makro to log if a assertion has failed in release build.
#define LOG_ASSERT(Y,X) if(!(X)) {\
				assert((X));\
				BOOST_LOG_SEV((Y),error)<<LOCATION_ALL\
							<< "Assertion failed: ("\
							<<#X<<") !";\
			}

#define LOG(X,Y) BOOST_LOG_SEV(X,Y)<<LOCATION

#define MAIN_LOG(X) LOG(main_l::get(),X)

//The different serevrity levels
enum severity_level {
	normal,
	notification,
	warning,
	error,
	critical
};

using severity_channel_logger =
    boost::log::sources::severity_channel_logger_mt<severity_level,std::string>;

//Forward declaration
std::ostream& operator<< (std::ostream& strm, severity_level level);

//Init the global logger for the main channel
BOOST_LOG_INLINE_GLOBAL_LOGGER_INIT(main_l, severity_channel_logger) {
	return severity_channel_logger(boost::log::keywords::channel = "MAIN");
}

/**
 * Turns the given path to the path that gets diaplyes in the log messages.
 *
 * It should at some point have a folder calles src. But this is given since
 * the project only gets build if theres a folder src.
 *
 * @param path the path to convert
 */
std::string getDisplayPath(const std::string& path);

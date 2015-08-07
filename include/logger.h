#pragma once

#include <string>
#include <iostream>

#include <boost/log/sources/severity_channel_logger.hpp>
#include <boost/log/sources/global_logger_storage.hpp>
#include <boost/log/trivial.hpp>

#include <assert.h>

//This macro is the location of this statement as string.
//Before you can use it in your log messages you should call INIT_LOCATION at the start of the fiel-
#define LOCATION_ALL (std::string("(")+displayPath+" : "+std::to_string(__LINE__)+") ")

//If you want to use LOCATION or LOCATION_ALL in your log messages then you have to call
//this INIT_LOCATION at the start of your file.
#define INIT_LOCATION namespace {std::string displayPath=getDisplayPath(std::string(__FILE__));}

#ifdef _DEBUG_

//This macro defines a string which holds the location of the occurence of LOCATION.
//But only in debug build
#define LOCATION LOCATION_ALL

#else

//In release buidl this macro will be resolved to an empty string.
#define LOCATION ""

#endif

//defines a makro to log if a assertion has failed in release build.
//In debug build the assertion stops the execution as usual.
//X is the logger.
//Y is the expression to assert.
#define LOG_ASSERT(Y,X) if(!(X)) {\
				assert((X));\
				BOOST_LOG_SEV((Y),error)<<LOCATION_ALL\
							<< "Assertion failed: ("\
							<<#X<<") !";\
			}

//This makro is a short form for logging. It already uses LOCATION.
//X is the logger, Y is the severity_level
#define LOG(X,Y) BOOST_LOG_SEV(X,Y)<<LOCATION

//Logs a message with LOG(X,Y) to the logger main_l::get()
#define MAIN_LOG(X) LOG(main_l::get(),X)

//The different serevrity levels for the logger
enum severity_level {
	normal,
	notification,
	warning,
	error,
	critical
};

using severity_channel_logger =
    boost::log::sources::severity_channel_logger_mt<severity_level,std::string>;

//Forward declaration the operator that converts the severity_level to a string
std::ostream& operator<< (std::ostream& strm, severity_level level);

//Init the global logger for the main channel
BOOST_LOG_INLINE_GLOBAL_LOGGER_INIT(main_l, severity_channel_logger) {
	return severity_channel_logger(boost::log::keywords::channel = "MAIN");
}

/**
 * Turns the given path to the path that gets diaplyed in the log messages.
 *
 * The __FILE__ macro should at some point have a folder called src. But this is given since
 * the project only gets build if theres a folder src.
 *
 * @param path the path to convert
 */
std::string getDisplayPath(const std::string& path);

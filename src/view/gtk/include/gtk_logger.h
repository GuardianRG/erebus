#pragma once

#include <logger.h>

BOOST_LOG_INLINE_GLOBAL_LOGGER_INIT(gtk_l, severity_channel_logger) {
	return severity_channel_logger(boost::log::keywords::channel = "VIEW_GTK");
}

//Logs a call of the constructor.
#define LOG_CONSTRUCTOR BOOST_LOG_SEV(gtk_l::get(),normal)<<LOCATION<<"Constructing "<<classname()<<" '"<<getID()<<"'";

//Logs a coll of the destructor.
#define LOG_DESTRUCTOR BOOST_LOG_SEV(gtk_l::get(),normal)<<LOCATION<<"Destructing "<<classname()<<" '"<<getID()<<"'";

//Logs a message with the errorlevel X to the logger gtk_l::get().
#define LOG_GTK(X) LOG(gtk_l::get(),X)

//Logs the assertion of the expression X to the logger gtk_l::get().
#define LOG_ASSERT_GTK(X) LOG_ASSERT(gtk_l::get(),X)

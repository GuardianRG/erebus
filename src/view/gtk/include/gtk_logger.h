#pragma once

#include <logger.h>

BOOST_LOG_INLINE_GLOBAL_LOGGER_INIT(gtk_l, severity_channel_logger) {
	return severity_channel_logger(boost::log::keywords::channel = "VIEW_GTK");
}


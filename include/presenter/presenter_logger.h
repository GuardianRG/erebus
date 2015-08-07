#pragma once

#include <logger.h>

BOOST_LOG_INLINE_GLOBAL_LOGGER_INIT(presenter_l, severity_channel_logger) {
	return severity_channel_logger(boost::log::keywords::channel = "PRESENTER");
}

#define LOG_ASSERT_PRESENTER(X) LOG_ASSERT(presenter_l::get(),X)

#define LOG_PRESENTER(X) LOG(presenter_l::get(),X)

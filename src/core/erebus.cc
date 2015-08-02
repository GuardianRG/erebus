#include <exception>
#include <stdexcept>
#include <iostream>
#include <string>
#include <memory>

#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sources/severity_channel_logger.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/common.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/attributes/timer.hpp>
#include <boost/log/attributes/named_scope.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/support/date_time.hpp>

#include <logger.h>
#include <view/view_preferences_loader.h>
#include <view/gui_manager.h>
#include <model.h>
#include <gtk_gui_manager.h>
#include <file_system.h>


INIT_LOCATION;

/**
 * Initializes the logger.
 */
void initLogging() {
    createDirectory("logs");

    boost::log::add_console_log(std::clog,
                                boost::log::keywords::format = boost::log::expressions::stream
                                                               << boost::log::expressions::attr<unsigned int>("LineID")
                                                               << ": [" <<
                                                               boost::log::expressions::attr<std::string>("Channel")
                                                               << "] \t[" <<
                                                               boost::log::expressions::attr<severity_level>("Severity")
                                                               << "]\t" << boost::log::expressions::message
    );

    boost::log::add_file_log
            (
                    "logs/%Y_%m_%d_%H_%M_%S.log",
                    boost::log::keywords::auto_flush = true,
                    boost::log::keywords::filter =
                            boost::log::expressions::attr<severity_level>("Severity") >= warning,

                    boost::log::keywords::format = boost::log::expressions::stream
                                                   << boost::log::expressions::attr<unsigned int>("LineID")
                                                   << ": "
                                                   << boost::log::expressions::format_date_time<
                            boost::posix_time::ptime>("TimeStamp", "%Y-%m-%d, %H:%M:%S.%f")
                                                   << " [" << boost::log::expressions::format_date_time<
                            boost::log::attributes::timer::value_type>("Uptime", "%O:%M:%S")
                                                   << "] [" << boost::log::expressions::attr<std::string>("Channel")
                                                   << "] [" << boost::log::expressions::attr<severity_level>("Severity")
                                                   << "] " << boost::log::expressions::message
            );

    boost::log::add_common_attributes();
    boost::log::core::get()->add_global_attribute("LineID",
                                                  boost::log::attributes::counter<unsigned int>(1));

    boost::log::core::get()->add_global_attribute("Uptime", boost::log::attributes::timer());

    boost::log::core::get()->add_thread_attribute("Scope",
                                                  boost::log::attributes::named_scope());

    BOOST_LOG_FUNCTION();
}

/**
 * Loads the view preferences.
 *
 * First the default preferences get loaded and the the custom preferences.
 */
void loadViewPreferences() {
    auto viewPrefLoader = erebus::ViewPreferencesLoader{};
    //Load defaulr preferences first to assure everything has a solid initiliazation value
    viewPrefLoader.loadDefaultViewPreferences();
    //The load the custom preferences
    viewPrefLoader.loadViewPreferences();
}

int main(int argc, char *argv[]) {
    try {
        initLogging();
    } catch (std::exception const &e) {
        std::cout << e.what()
        << std::endl
        << "Something went wronge while building the logger!"
        << std::endl
        << "Exiting..."
        << std::endl;
        return 1;
    }
#ifndef _DEBUG_
try {
#endif
	
    BOOST_LOG_SEV(main_l::get(), normal) << LOCATION << "Boost logger initialized";

    BOOST_LOG_SEV(main_l::get(), normal) << LOCATION << "Initializing model";
    auto model = std::make_shared<erebus::Model>();
    
#ifdef _GTKMM_
    auto guiManager=std::make_unique<erebus::GTK_GUIManager>();
#else
    BOOST_LOG_SEV(main_l::get(),error)<<LOCATION<<"Could not find a graphics library";
    return 1;
#endif
    BOOST_LOG_SEV(main_l::get(), normal) << LOCATION << "Running gui";
    //gui.runGUI();
    BOOST_LOG_SEV(main_l::get(), normal) << LOCATION << "Stopping gui";
    
#ifndef _DEBUG_
}catch(std::exception& e) {
	BOOST_LOG_SEV(main_l::get(),error)<<LOCATION<<"Unexpected error:"<<e.what();
}
#endif
    return 0;
}

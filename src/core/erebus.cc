#include <exception>
#include <stdexcept>
#include <iostream>
#include <assert.h>
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

#include <view/interfaces/i_gui_manager.h>

#include <logger.h>
#include <view/view_preferences_loader.h>
#include <model.h>
#include <file_system.h>

#ifdef _GTKMM_
#include <gtk_gui_manager.h>
#include <glibmm/exception.h>
#endif

namespace logging = boost::log;
namespace expr = logging::expressions;
namespace attrs = logging::attributes;


INIT_LOCATION;

/**
 * Initializes the logger.
 */
void initLogging() {
	//Create the directory in which the log files get stored
	createDirectory("logs");

	//Add the console log
	logging::add_console_log(std::clog,
	                         logging::keywords::format = expr::stream
	                                 << expr::attr<unsigned int>("LineID")
	                                 << ": [" <<
	                                 expr::attr<std::string>("Channel")
	                                 << "] \t[" <<
	                                 expr::attr<severity_level>("Severity")
	                                 << "]\t" << expr::message
	                        );

	//Add the file log
	logging::add_file_log
	(
	    "logs/%Y_%m_%d_%H_%M_%S.log",
	    logging::keywords::auto_flush = true,
	    logging::keywords::filter =
	        expr::attr<severity_level>("Severity") >= warning,

	    logging::keywords::format = expr::stream<<expr::attr<unsigned int>("LineID")<< ": "<<
	                                expr::format_date_time<
	                                boost::posix_time::ptime>("TimeStamp", "%Y-%m-%d, %H:%M:%S.%f")
	                                << " [" << expr::format_date_time<
	                                attrs::timer::value_type>("Uptime", "%O:%M:%S")
	                                << "] [" << expr::attr<std::string>("Channel")
	                                << "] [" << expr::attr<severity_level>("Severity")
	                                << "] " << expr::message
	);

	logging::add_common_attributes();

	logging::core::get()->add_global_attribute("LineID",attrs::counter<unsigned int>(1));

	logging::core::get()->add_global_attribute("Uptime",attrs::timer());

	logging::core::get()->add_thread_attribute("Scope",attrs::named_scope());
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
	BOOST_LOG_SEV(main_l::get(), normal) << LOCATION << "Boost logger initialized";

#ifndef _DEBUG_
	try {
#endif
		BOOST_LOG_SEV(main_l::get(), normal) << LOCATION << "Initializing model";
		auto model = std::make_shared<erebus::Model>();

#ifndef _DEBUG_
	} catch(const std::exception& e) {
		BOOST_LOG_SEV(main_l::get(),error)<<LOCATION
		                                  <<"Unexpected error while initializing the model: "
		                                  <<e.what();
		return 2;
	}
#endif

	auto guiManager=std::unique_ptr<erebus::IGUIManager>(nullptr);

#ifndef _DEBUG_
	try {
#endif

#ifdef _GTKMM_
		guiManager=std::unique_ptr<erebus::IGUIManager>(std::make_unique<erebus::GTK_GUIManager>());
		auto gmc=static_cast<erebus::GTK_GUIManager*>(guiManager.get());
		gmc->initialize(argc,argv);
#else
		BOOST_LOG_SEV(main_l::get(),error)<<LOCATION
		                                  <<"Could not find a graphics library";
		return 3;
#endif

#ifndef _DEBUG_
	} catch(const std::exception& e) {
		BOOST_LOG_SEV(main_l::get(),error)<<LOCATION
		                                  <<"Unexpected error while building the gui: "
		                                  <<e.what();
		return 4;
	}
#ifdef _GTKMM_
	catch(const Glib::Exception& e) {
		BOOST_LOG_SEV(main_l::get(),error)<<LOCATION
		                                  <<"Unexpected error while building the gui: "
		                                  <<e.what();
		return 4;
	}
#endif

#endif
	assert(guiManager.get()!=nullptr);

#ifndef _DEBUG_
	try {
#endif
		BOOST_LOG_SEV(main_l::get(), normal) << LOCATION << "Running gui";
		guiManager->runGUI();

#ifndef _DEBUG_
	} catch(const std::exception& e) {
		BOOST_LOG_SEV(main_l::get(),error)<<LOCATION
		                                  <<"Unexpected error occured: "
		                                  <<e.what();

		guiManager->showMessageDialog("An unexpected error has occured!",e.what(),
		                              erebus::ErrorLevel::ERROR);

		return 5;
	}
#ifdef _GTKMM_
	catch(const Glib::Exception& e) {
		BOOST_LOG_SEV(main_l::get(),error)<<LOCATION
		                                  <<"Unexpected error occured: "
		                                  <<e.what();

		guiManager->showMessageDialog("An unexpected error has occured!",e.what(),
		                              erebus::ErrorLevel::ERROR);

		return 5;
	}
#endif

#endif
	BOOST_LOG_SEV(main_l::get(), normal) << LOCATION << "Stopping gui";


	return 0;
}

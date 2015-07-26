#include <exception>
#include <stdexcept>
#include <iostream>
#include <string>
#include <sys/stat.h>
#include <dirent.h>
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
#include <view/gui_manager.h>
#include <model.h>

/**
 * Creates a directory.
 *
 * It uses linux functions. If the directory already
 * exists noting happens.
 *
 * @param path name of the directory
 */
void createDirectory_Linux(std::string path) {
	if(!opendir(path.c_str())) {
		const int dir_err = mkdir(path.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
		if (dir_err<0) {
			std::string errorMessage="Directory '"+path+"'could not be created!";
			throw std::runtime_error(errorMessage);
		}
	}
}

/**
 * Initializes the logger.
 */
void initLogging() {
	createDirectory_Linux("logs");

	boost::log::add_console_log(std::clog, 
				boost::log::keywords::format = "%LineID%: [%Channel%]: %Message%");

	boost::log::add_file_log
	(
	    "logs/%Y_%m_%d_%H_%M_%S.log",
	    boost::log::keywords::auto_flush = true ,
	    boost::log::keywords::filter = 
			boost::log::expressions::attr< severity_level >("Severity") >= warning,
	 
	    boost::log::keywords::format = boost::log::expressions::stream
			<<boost::log::expressions::attr<unsigned int>("LineID")
			<< ": "
			<<boost::log::expressions::format_date_time< 
				boost::posix_time::ptime >("TimeStamp", "%Y-%m-%d, %H:%M:%S.%f")
			<< " [" << boost::log::expressions::format_date_time< 
				boost::log::attributes::timer::value_type >("Uptime", "%O:%M:%S")
			<< "] [" << boost::log::expressions::attr<std::string>("Channel")
			<< "] <" << boost::log::expressions::attr< severity_level >("Severity")
			<< "> " << boost::log::expressions::message
	);

	boost::log::add_common_attributes();
	boost::log::core::get()->add_global_attribute("LineID", 
					boost::log::attributes::counter< unsigned int >(1));
	
	boost::log::core::get()->add_global_attribute("Uptime", boost::log::attributes::timer());
	
	boost::log::core::get()->add_thread_attribute("Scope", 
					boost::log::attributes::named_scope());

	BOOST_LOG_FUNCTION();
}

int main(int argc, char *argv[]) {
	try {
		initLogging();
	} catch(std::exception const& e) {
		std::cout<<e.what()
		         <<std::endl
		         <<"Something went wronge while building the logger!"
		         <<std::endl
		         <<"Exiting..."
		         <<std::endl;
		return 1;
	}
	BOOST_LOG_SEV(main_l::get(),normal)<<LOCATION<<"Boost logger initialized";

	BOOST_LOG_SEV(main_l::get(),normal)<<LOCATION<<"Initializing model";
	auto model(std::make_shared<erebus::Model>());

	auto gui=erebus::GUIManager::create(model,argc,argv);
	BOOST_LOG_SEV(main_l::get(),normal)<<LOCATION<<"Running gui";
	gui->runGUI();
	BOOST_LOG_SEV(main_l::get(),normal)<<LOCATION<<"Stopped gui";
	return 0;
}

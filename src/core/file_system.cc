#include <file_system.h>

#include <boost/filesystem.hpp>

#include <sys/stat.h>
#include <string>
#include <dirent.h>
#include <iostream>
#include <fstream>


void createDirectory(const std::string& path) {
	boost::filesystem::create_directories(path);
}

bool doesDirectoryExist(const std::string& path) {
	return opendir(path.c_str());
}

bool doesFileExist(const std::string& path) {
	struct stat buffer;
	return (stat (path.c_str(), &buffer) == 0);
}

void createFile(const std::string& path) {
	if(!doesFileExist(path)) {
	std::ofstream outfile (path);
	outfile <<"";
	outfile.close();
	}
}

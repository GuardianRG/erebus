#pragma once

#include <string>

/**
 * Checks whether the given directory exists.
 *
 * @param path the directory to Checks
 * @return true if the directory already exists
 */
bool doesDirectoryExist(const std::string& path);

/**
 * Creates a directory.
 *
 * If the directory already exists nothing happens.
 * It does create directories recursivly.
 *
 * @param path name of the directory
 */
void createDirectory(const std::string& path);

/**
 * Checks whether the given file exists.
 *
 * @param path the file to check
 * @return true if the file exists
 */
bool doesFileExist(const std::string& path);

/**
 * Creates the file if it doesnt exist.
 * 
 * @param path the fileto create
 */
void createFile(const std::string& path);
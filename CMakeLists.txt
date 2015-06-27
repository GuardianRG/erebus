cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(erebus CXX)


find_package(PkgConfig REQUIRED)

pkg_check_modules(GTKMM gtkmm-3.0)

add_subdirectory(src)
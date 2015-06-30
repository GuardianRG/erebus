cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(erebus CXX)

#enable testing with googletest
add_subdirectory(lib/gtest-1.7.0)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

#provide gtkmm headers
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM gtkmm-3.0)
link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})

#provide boost headers
find_package(Boost REQUIRED )
include_directories( ${Boost_INCLUDE_DIR} )

#add source directories
add_subdirectory(src)
add_subdirectory(test)

#include header files
include_directories(include)

#set compileflags
SET(erebus_CXX_FLAGS "" CACHE STRING "Flags to use in directory Bar")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${erebus_CXX_FLAGS} -std=c++14 -Wall -Werror")

#create executable
add_executable(erebus ${SOURCE})

target_link_libraries(erebus ${GTKMM_LIBRARIES})
target_link_libraries(erebus ${Boost_LIBRARIES} )
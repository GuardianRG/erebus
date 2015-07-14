cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(erebus CXX)


###########################################
##Enable testing with googletest
###########################################

# Enable ExternalProject CMake module
include(ExternalProject)

# Add gtest
ExternalProject_Add(
    googletest
    SVN_REPOSITORY http://googletest.googlecode.com/svn/trunk/
    TIMEOUT 10
    CMAKE_ARGS -Dgtest_force_shared_crt=ON
    INSTALL_COMMAND ""
    LOG_DOWNLOAD ON
    LOG_CONFIGURE ON
    LOG_BUILD ON
)

# Specify include dir
ExternalProject_Get_Property(googletest source_dir)
include_directories(${source_dir}/include)


# Specify MainTest's link libraries
ExternalProject_Get_Property(googletest binary_dir)
if(MSVC)
  set(Suffix ".lib")
else()
  set(Suffix ".a")
  set(Pthread "-pthread")
endif()

set(gtest_LIBRARIES 
	${binary_dir}/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${Suffix}
	${binary_dir}/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main${Suffix}
	${Pthread}
)

enable_testing()

##############################################
##End of googletest
##############################################


#provide gtkmm headers

if(UNIX)
	find_package(PkgConfig REQUIRED)
	
	pkg_check_modules(GTKMM gtkmm-3.0)
	if(GTKMM_FOUND)
		link_directories(${GTKMM_LIBRARY_DIRS})
		include_directories(${GTKMM_INCLUDE_DIRS})
	endif()
endif()

#provide boost headers
#find_package(Boost REQUIRED )
#include_directories( ${Boost_INCLUDE_DIR} )

#include header files
include_directories(include)

#set compileflags
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${erebus_CXX_FLAGS} -std=c++14 -Wall -Werror")

#add source directories
add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(test)

#create executable
add_executable(erebus ${SOURCE} ${HEADER_FILES})

add_subdirectory(resources)

if(GTKMM_FOUND)
	target_link_libraries(erebus gtk_gui)
endif()

target_link_libraries(erebus ${GTKMM_LIBRARIES})
target_link_libraries(erebus ${Boost_LIBRARIES})

add_custom_command(
	TARGET erebus POST_BUILD
    	COMMAND ${PROJECT_SOURCE_DIR}/format-code.sh
    	DEPENDS "${PROJECT_SOURCE_DIR}/format-code.sh"
    	WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    	COMMENT "Formats the code")
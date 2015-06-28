
set(observer_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/observer.cc
	${CMAKE_CURRENT_SOURCE_DIR}/observable.cc
	${CMAKE_CURRENT_SOURCE_DIR}/action.cc
)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Werror")

add_library(observer ${observer_SOURCES})
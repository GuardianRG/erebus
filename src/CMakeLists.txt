link_directories(${GTKMM_LIBRARY_DIRS}  )

include_directories(${GTKMM_INCLUDE_DIRS}  )


add_subdirectory(core)
add_subdirectory(gui)
add_subdirectory(pattern)


SET(erebus_CXX_FLAGS "" CACHE STRING "Flags to use in directory Bar")

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${erebus_CXX_FLAGS} -std=c++14 -Wall -Werror")

add_executable(erebus ${SOURCE})

target_link_libraries(erebus ${GTKMM_LIBRARIES}  )
target_link_libraries(erebus observer)


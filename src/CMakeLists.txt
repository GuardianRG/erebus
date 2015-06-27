
link_directories(${GTKMM_LIBRARY_DIRS}  )

include_directories(${GTKMM_INCLUDE_DIRS}  )


add_subdirectory(core)
add_subdirectory(gui)

add_executable(erebus ${SOURCE})

target_link_libraries(erebus ${GTKMM_LIBRARIES}  )


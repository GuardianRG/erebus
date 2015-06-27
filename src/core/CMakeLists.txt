link_directories(${GTKMM_LIBRARY_DIRS}  )

include_directories(${GTKMM_INCLUDE_DIRS}  )

add_executable(erebus erebus.cc)


target_link_libraries(erebus ${GTKMM_LIBRARIES}  )
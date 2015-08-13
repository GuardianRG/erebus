#resources/view/CMakeLists.txt

if(GTKMM_FOUND)
	add_subdirectory(gtk)
endif()

###########################
#Add default_view_preferences.pref
###########################
add_custom_command(
    OUTPUT "${PROJECT_BINARY_DIR}/resources/default_view_preferences.pref"
    COMMAND ${CMAKE_COMMAND} -E copy "${PROJECT_SOURCE_DIR}/resources/view/default_view_preferences.pref" "${PROJECT_BINARY_DIR}/resources/"
    DEPENDS "${PROJECT_SOURCE_DIR}/resources/view/default_view_preferences.pref"
    COMMENT "add default view preferences file")
 
add_custom_target(default_view_preferences.pref DEPENDS "${PROJECT_BINARY_DIR}/resources/default_view_preferences.pref")

add_dependencies(erebus default_view_preferences.pref)

###########################
#src/view/CMakeLists.txt

if(GTKMM_FOUND)
	add_subdirectory(gtk)
endif()

set(SOURCE
	${SOURCE}
	${CMAKE_CURRENT_SOURCE_DIR}/view_preferences.cc
	${CMAKE_CURRENT_SOURCE_DIR}/view_preferences_saver.cc
	${CMAKE_CURRENT_SOURCE_DIR}/view_preferences_loader.cc
	PARENT_SCOPE
)


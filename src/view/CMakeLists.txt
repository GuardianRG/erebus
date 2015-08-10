#src/view/CMakeLists.txt

if(GTKMM_FOUND)
	add_subdirectory(gtk)
endif()

add_subdirectory(preferences)

set(SOURCE
	${SOURCE}
	${CMAKE_CURRENT_SOURCE_DIR}/view_preference.cc
	${CMAKE_CURRENT_SOURCE_DIR}/view_preference_factory.cc
	${CMAKE_CURRENT_SOURCE_DIR}/view_preferences_manager.cc
	${CMAKE_CURRENT_SOURCE_DIR}/view_preferences_saver.cc
	${CMAKE_CURRENT_SOURCE_DIR}/view_preferences_loader.cc
	PARENT_SCOPE
)


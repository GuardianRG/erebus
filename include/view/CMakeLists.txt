#include/view/CMakeLists.txt

add_subdirectory(interfaces)
add_subdirectory(preferences)

set(VIEW_HEADERS
	${VIEW_HEADERS}
	${CMAKE_CURRENT_SOURCE_DIR}/view_type.h
	${CMAKE_CURRENT_SOURCE_DIR}/view_preference.h
	${CMAKE_CURRENT_SOURCE_DIR}/view_preference_factory.h
	${CMAKE_CURRENT_SOURCE_DIR}/view_preferences_manager.h
	${CMAKE_CURRENT_SOURCE_DIR}/view_preferences_saver.h
	${CMAKE_CURRENT_SOURCE_DIR}/view_preferences_loader.h
	PARENT_SCOPE
)
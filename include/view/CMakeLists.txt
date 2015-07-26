#include/view/CMakeLists.txt

set(VIEW_HEADERS
	${VIEW_HEADERS}
	${CMAKE_CURRENT_SOURCE_DIR}/gui_manager.h
	${CMAKE_CURRENT_SOURCE_DIR}/view_type.h
	${CMAKE_CURRENT_SOURCE_DIR}/view_preferences.h
	${CMAKE_CURRENT_SOURCE_DIR}/view_preferences_saver.h
	${CMAKE_CURRENT_SOURCE_DIR}/view_preferences_loader.h
	PARENT_SCOPE
)
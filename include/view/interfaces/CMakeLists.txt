#include/view/interfaces/CMakeLists.txt

set(VIEW_HEADERS
	${VIEW_HEADERS}
	${CMAKE_CURRENT_SOURCE_DIR}/i_main_window.h
	${CMAKE_CURRENT_SOURCE_DIR}/i_window.h
	${CMAKE_CURRENT_SOURCE_DIR}/i_view.h
	${CMAKE_CURRENT_SOURCE_DIR}/i_empty_view.h
	${CMAKE_CURRENT_SOURCE_DIR}/i_gui_state_object.h
	PARENT_SCOPE
)
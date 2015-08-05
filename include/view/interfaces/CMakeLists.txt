#include/view/interfaces/CMakeLists.txt

set(VIEW_HEADERS
	${VIEW_HEADERS}
	${CMAKE_CURRENT_SOURCE_DIR}/i_main_window.h
	${CMAKE_CURRENT_SOURCE_DIR}/i_window.h
	${CMAKE_CURRENT_SOURCE_DIR}/i_view.h
	${CMAKE_CURRENT_SOURCE_DIR}/i_view_window.h
	${CMAKE_CURRENT_SOURCE_DIR}/i_empty_view.h
	${CMAKE_CURRENT_SOURCE_DIR}/i_hex_view.h
	${CMAKE_CURRENT_SOURCE_DIR}/i_view_container.h
	${CMAKE_CURRENT_SOURCE_DIR}/i_gui_manager.h
	${CMAKE_CURRENT_SOURCE_DIR}/i_gui_object.h
	${CMAKE_CURRENT_SOURCE_DIR}/i_view_container_settings_propagator.h
	PARENT_SCOPE
)
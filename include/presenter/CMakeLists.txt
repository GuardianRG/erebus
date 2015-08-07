#include/presenter/CMakeLists.txt

add_subdirectory(interfaces)

set(PRESENTER_HEADERS
	${PRESENTER_HEADERS}
	${CMAKE_CURRENT_SOURCE_DIR}/empty_view_presenter.h
	${CMAKE_CURRENT_SOURCE_DIR}/hex_view_presenter.h
	${CMAKE_CURRENT_SOURCE_DIR}/main_window_presenter.h
	${CMAKE_CURRENT_SOURCE_DIR}/view_window_presenter.h
	${CMAKE_CURRENT_SOURCE_DIR}/view_container_presenter.h
	${CMAKE_CURRENT_SOURCE_DIR}/presenter_logger.h
	PARENT_SCOPE
)
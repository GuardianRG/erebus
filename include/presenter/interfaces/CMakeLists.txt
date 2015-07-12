#include/presenter/interfaces/CMakeLists.txt


set(PRESENTER_HEADERS
	${VIEW_HEADERS}
	${CMAKE_CURRENT_SOURCE_DIR}/i_empty_view_presenter.h
	${CMAKE_CURRENT_SOURCE_DIR}/i_main_window_presenter.h
	${CMAKE_CURRENT_SOURCE_DIR}/i_presenter.h
	${CMAKE_CURRENT_SOURCE_DIR}/i_view_presenter.h
	${CMAKE_CURRENT_SOURCE_DIR}/i_view_container_presenter.h
	${CMAKE_CURRENT_SOURCE_DIR}/i_window_presenter.h
	PARENT_SCOPE
)
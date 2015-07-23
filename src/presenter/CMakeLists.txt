#src/presenter/CMakeLists.txt

set(SOURCE
	${SOURCE}
	${CMAKE_CURRENT_SOURCE_DIR}/empty_view_presenter.cc
	${CMAKE_CURRENT_SOURCE_DIR}/hex_view_presenter.cc
	${CMAKE_CURRENT_SOURCE_DIR}/main_window_presenter.cc
	${CMAKE_CURRENT_SOURCE_DIR}/view_container_presenter.cc
	${CMAKE_CURRENT_SOURCE_DIR}/view_window_presenter.cc
	${CMAKE_CURRENT_SOURCE_DIR}/window_presenter.cc
	PARENT_SCOPE
)
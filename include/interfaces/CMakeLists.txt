#include/interfaces/CMakeLists.txt

set(HEADER_FILES 
	${HEADER_FILES}
	${CMAKE_CURRENT_SOURCE_DIR}/i_main_view.h
	${CMAKE_CURRENT_SOURCE_DIR}/i_view.h
	${CMAKE_CURRENT_SOURCE_DIR}/i_application_manager.h
	${CMAKE_CURRENT_SOURCE_DIR}/i_main_view_presenter.h
	${CMAKE_CURRENT_SOURCE_DIR}/i_model.h
	${CMAKE_CURRENT_SOURCE_DIR}/i_presenter.h
	PARENT_SCOPE
)
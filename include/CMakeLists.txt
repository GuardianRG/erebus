#include/CMakeLists.txt

set(VIEW_HEADERS
	${VIEW_HEADERS}
)

add_subdirectory(exceptions)
add_subdirectory(interfaces)
add_subdirectory(view)

set(HEADER_FILES 
	${HEADER_FILES}
	${VIEW_HEADERS}
	${CMAKE_CURRENT_SOURCE_DIR}/file_reader.h
	${CMAKE_CURRENT_SOURCE_DIR}/types.h
	${CMAKE_CURRENT_SOURCE_DIR}/file.h
	${CMAKE_CURRENT_SOURCE_DIR}/model.h
	PARENT_SCOPE
)
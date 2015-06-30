#include/CMakeLists.txt

add_subdirectory(exceptions)

set(HEADER_FILES 
	${HEADER_FILES}
	${CMAKE_CURRENT_SOURCE_DIR}/file_reader.h
	${CMAKE_CURRENT_SOURCE_DIR}/types.h
	${CMAKE_CURRENT_SOURCE_DIR}/file.h
	PARENT_SCOPE
)
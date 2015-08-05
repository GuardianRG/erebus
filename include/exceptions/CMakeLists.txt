#include/execptions/CMakeLists.txt

set(HEADER_FILES 
	${HEADER_FILES}
	${CMAKE_CURRENT_SOURCE_DIR}/file_not_found.h
	${CMAKE_CURRENT_SOURCE_DIR}/invalid_parent.h
	PARENT_SCOPE
)
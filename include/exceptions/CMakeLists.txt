#include/execptions/CMakeLists.txt

set(HEADER_FILES 
	${HEADER_FILES}
	${CMAKE_CURRENT_SOURCE_DIR}/file_not_found.h
	${CMAKE_CURRENT_SOURCE_DIR}/invalid_parent.h
	${CMAKE_CURRENT_SOURCE_DIR}/no_such_element.h
	PARENT_SCOPE
)
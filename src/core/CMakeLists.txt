#src/core/CMakeLists.txt

add_subdirectory(file_types)

set(SOURCE
	${SOURCE}
	${CMAKE_CURRENT_SOURCE_DIR}/erebus.cc
	${CMAKE_CURRENT_SOURCE_DIR}/file_reader.cc
	${CMAKE_CURRENT_SOURCE_DIR}/logger.cc
	PARENT_SCOPE
)
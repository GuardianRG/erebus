add_subdirectory(file_types)
add_subdirectory(exceptions)

set(SOURCE 
	${SOURCE}
	${CMAKE_CURRENT_SOURCE_DIR}/erebus.cc
	${CMAKE_CURRENT_SOURCE_DIR}/file_reader.cc
	PARENT_SCOPE
)
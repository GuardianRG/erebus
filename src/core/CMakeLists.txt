#src/core/CMakeLists.txt

#Add sourcefiles to erebus executable
set(SOURCE
	${SOURCE}
	${CMAKE_CURRENT_SOURCE_DIR}/erebus.cc
	${CMAKE_CURRENT_SOURCE_DIR}/file_reader.cc
	PARENT_SCOPE
)
#test/core/CMakeLists.txt

add_executable(file_reader_test 
	file_reader_test.cc 
	${CMAKE_SOURCE_DIR}/src/core/file_reader.cc 
	${CMAKE_SOURCE_DIR}/include/file_reader.h 
	${CMAKE_SOURCE_DIR}/include/types.h
)
target_link_libraries(file_reader_test gtest gtest_main)
add_test(file_reader_test file_reader_test)

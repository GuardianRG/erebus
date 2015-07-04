#test/core/file_types/CMakeLists.txt

#create unit test for file.cc
add_executable(core-file_types__file_test 
	file_test.cc 
	${CMAKE_SOURCE_DIR}/src/core/file_types/file.cc 
	${CMAKE_SOURCE_DIR}/include/file.h 
	${CMAKE_SOURCE_DIR}/include/types.h
)
add_dependencies(core-file_types__file_test googletest)
target_link_libraries(core-file_types__file_test ${gtest_LIBRARIES})
add_test(core-file_types__file_test core-file_types__file_test)

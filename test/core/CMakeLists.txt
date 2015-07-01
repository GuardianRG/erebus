#test/core/CMakeLists.txt

#create unit test for file_reader.cc
add_executable(core__file_reader_test 
	file_reader_test.cc 
	${CMAKE_SOURCE_DIR}/src/core/file_reader.cc 
	${CMAKE_SOURCE_DIR}/include/file_reader.h 
	${CMAKE_SOURCE_DIR}/include/types.h
)

# Create dependency of MainTest on googletest
add_dependencies(core__file_reader_test googletest)
target_link_libraries(
    core__file_reader_test
    debug ${binary_dir}/DebugLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${Suffix}
    optimized ${binary_dir}/ReleaseLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${Suffix}
    ${Pthread})

    
add_test(core__file_reader_test core__file_reader_test)

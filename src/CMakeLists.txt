#src/CMakeLists.txt

add_subdirectory(core)
add_subdirectory(view)
add_subdirectory(presenter)

set(SOURCE
	${SOURCE}
	PARENT_SCOPE
)


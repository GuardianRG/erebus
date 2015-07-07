#src/view/CMakeLists.txt

if(GTKMM_FOUND)
	add_subdirectory(gtk)
endif()

set(SOURCE
	${SOURCE}
	PARENT_SCOPE
)


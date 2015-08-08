#src/view/gtk/CMakeLists.txt

include_directories(include)

set(SOURCE
	${SOURCE}
	${CMAKE_CURRENT_SOURCE_DIR}/gtk_empty_view.cc
	${CMAKE_CURRENT_SOURCE_DIR}/gtk_hex_view.cc
	${CMAKE_CURRENT_SOURCE_DIR}/gtk_main_window.cc
	${CMAKE_CURRENT_SOURCE_DIR}/gtk_builder_factory.cc
	${CMAKE_CURRENT_SOURCE_DIR}/gtk_view.cc
	${CMAKE_CURRENT_SOURCE_DIR}/gtk_view_container.cc
	${CMAKE_CURRENT_SOURCE_DIR}/gtk_gui_manager.cc
	${CMAKE_CURRENT_SOURCE_DIR}/gtk_view_window.cc
	${CMAKE_CURRENT_SOURCE_DIR}/gtk_window.cc
	${CMAKE_CURRENT_SOURCE_DIR}/glade_file.cc
	PARENT_SCOPE
)

set(HEADER_FILES
	${HEADER_FILES}
	PARENT_SCOPE
)

add_subdirectory(include)
#src/view/gtk/CMakeLists.txt

include_directories(include)

set(GTK_GUI_SOURCES
	${GTK_GUI_SOURCES}
	${CMAKE_CURRENT_SOURCE_DIR}/gtk_empty_view.cc
	${CMAKE_CURRENT_SOURCE_DIR}/gtk_hex_view.cc
	${CMAKE_CURRENT_SOURCE_DIR}/gtk_main_window.cc
	${CMAKE_CURRENT_SOURCE_DIR}/gtk_builder_factory.cc
	${CMAKE_CURRENT_SOURCE_DIR}/gtk_view.cc
	${CMAKE_CURRENT_SOURCE_DIR}/gtk_view_container.cc
	${CMAKE_CURRENT_SOURCE_DIR}/gtk_view_window.cc
	${CMAKE_CURRENT_SOURCE_DIR}/gtk_window.cc
	${CMAKE_CURRENT_SOURCE_DIR}/gtk_view_container_settings_propagator.cc
	${CMAKE_CURRENT_SOURCE_DIR}/glade_files.cc
)

set(GTK_GUI_HEADERS
	${GTK_GUI_HEADERS}
)

add_subdirectory(include)
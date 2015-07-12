#src/view/gtk/CMakeLists.txt

include_directories(include)

set(GTK_GUI_SOURCES
	${GTK_GUI_SOURCES}
	${CMAKE_CURRENT_SOURCE_DIR}/gtk_empty_view.cc
	${CMAKE_CURRENT_SOURCE_DIR}/gtk_main_window.cc
	${CMAKE_CURRENT_SOURCE_DIR}/gui_manager.cc
	${CMAKE_CURRENT_SOURCE_DIR}/gtk_builder_factory.cc
	${CMAKE_CURRENT_SOURCE_DIR}/gtk_view.cc
	${CMAKE_CURRENT_SOURCE_DIR}/gtk_view_container.cc
)

set(GTK_GUI_HEADERS
	${GTK_GUI_SOURCES}
)

add_subdirectory(include)

add_library(gtk_gui STATIC ${GTK_GUI_SOURCES} ${GTK_GUI_HEADERS} ${VIEW_HEADERS} ${PRESENTER_HEADERS})
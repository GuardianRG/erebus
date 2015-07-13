#src/view/gtk/include/CMakeLists.txt

set(GTK_GUI_HEADERS
	${GTK_GUI_SOURCES}
	${CMAKE_CURRENT_SOURCE_DIR}/gtk_empty_view.h
	${CMAKE_CURRENT_SOURCE_DIR}/gtk_main_window.h
	${CMAKE_CURRENT_SOURCE_DIR}/gtk_builder_factory.h
	${CMAKE_CURRENT_SOURCE_DIR}/gtk_view.h
	${CMAKE_CURRENT_SOURCE_DIR}/gtk_gui_state_object.h
	${CMAKE_CURRENT_SOURCE_DIR}/gtk_view_container.h
	${CMAKE_CURRENT_SOURCE_DIR}/gtk_view_builder.h
	PARENT_SCOPE
)
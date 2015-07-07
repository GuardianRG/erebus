#resources/view/gtk/CMakeLists.txt

###########################
#Add main_window.glade
###########################
add_custom_command(
    OUTPUT "${PROJECT_BINARY_DIR}/resources/main_window.glade"
    COMMAND ${CMAKE_COMMAND} -E copy "${PROJECT_SOURCE_DIR}/resources/view/gtk/main_window.glade" "${PROJECT_BINARY_DIR}/resources/"
    DEPENDS "${PROJECT_SOURCE_DIR}/resources/view/gtk/main_window.glade"
    COMMENT "add file")
 
add_custom_target(main_window.glade DEPENDS "${PROJECT_BINARY_DIR}/resources/main_window.glade")

add_dependencies(erebus main_window.glade)

###########################
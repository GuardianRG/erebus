#resources/view/gtk/CMakeLists.txt

###########################
#Add view.glade
###########################
add_custom_command(
    OUTPUT "${PROJECT_BINARY_DIR}/resources/main_view.glade"
    COMMAND ${CMAKE_COMMAND} -E copy "${PROJECT_SOURCE_DIR}/resources/view/gtk/main_view.glade" "${PROJECT_BINARY_DIR}/resources/"
    DEPENDS "${PROJECT_SOURCE_DIR}/resources/view/gtk/main_view.glade"
    COMMENT "add file")
 
add_custom_target(main_view.glade DEPENDS "${PROJECT_BINARY_DIR}/resources/main_view.glade")

add_dependencies(erebus main_view.glade)

###########################
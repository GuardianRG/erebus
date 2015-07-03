#resources/view/gtk/CMakeLists.txt

###########################
#Add view.glade
###########################
add_custom_command(
    OUTPUT "${PROJECT_BINARY_DIR}/resources/view1.glade"
    COMMAND ${CMAKE_COMMAND} -E copy "${PROJECT_SOURCE_DIR}/resources/view/gtk/view1.glade" "${PROJECT_BINARY_DIR}/resources/"
    DEPENDS "${PROJECT_SOURCE_DIR}/resources/view/gtk/view1.glade"
    COMMENT "add file")
 
add_custom_target(view1.glade DEPENDS "${PROJECT_BINARY_DIR}/resources/view1.glade")

add_dependencies(erebus view1.glade)

###########################
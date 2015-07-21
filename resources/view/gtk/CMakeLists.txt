#resources/view/gtk/CMakeLists.txt

###########################
#Add main_window.glade
###########################
add_custom_command(
    OUTPUT "${PROJECT_BINARY_DIR}/resources/main_window.glade"
    COMMAND ${CMAKE_COMMAND} -E copy "${PROJECT_SOURCE_DIR}/resources/view/gtk/main_window.glade" "${PROJECT_BINARY_DIR}/resources/"
    DEPENDS "${PROJECT_SOURCE_DIR}/resources/view/gtk/main_window.glade"
    COMMENT "add main_window file")
 
add_custom_target(main_window.glade DEPENDS "${PROJECT_BINARY_DIR}/resources/main_window.glade")

add_dependencies(erebus main_window.glade)

###########################

###########################
#Add view_window.glade
###########################
add_custom_command(
    OUTPUT "${PROJECT_BINARY_DIR}/resources/view_window.glade"
    COMMAND ${CMAKE_COMMAND} -E copy "${PROJECT_SOURCE_DIR}/resources/view/gtk/view_window.glade" "${PROJECT_BINARY_DIR}/resources/"
    DEPENDS "${PROJECT_SOURCE_DIR}/resources/view/gtk/view_window.glade"
    COMMENT "add view_window file")
 
add_custom_target(view_window.glade DEPENDS "${PROJECT_BINARY_DIR}/resources/view_window.glade")

add_dependencies(erebus view_window.glade)

###########################

###########################
#Add hex_view.glade
###########################
add_custom_command(
    OUTPUT "${PROJECT_BINARY_DIR}/resources/hex_view.glade"
    COMMAND ${CMAKE_COMMAND} -E copy "${PROJECT_SOURCE_DIR}/resources/view/gtk/hex_view.glade" "${PROJECT_BINARY_DIR}/resources/"
    DEPENDS "${PROJECT_SOURCE_DIR}/resources/view/gtk/hex_view.glade"
    COMMENT "add hex_view file")
 
add_custom_target(hex_view.glade DEPENDS "${PROJECT_BINARY_DIR}/resources/hex_view.glade")

add_dependencies(erebus hex_view.glade)

###########################
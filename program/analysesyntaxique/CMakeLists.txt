add_custom_target(
   extern_lib
   COMMAND make
   WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}/program/analysesyntaxique/"
)
add_executable(analysesyntaxique main.cpp)
target_link_libraries(analysesyntaxique ${XmlProcessLib})
add_dependencies(analysesyntaxique extern_lib)

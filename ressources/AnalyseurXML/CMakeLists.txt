add_custom_target(
   extern_make
   COMMAND make
   WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}/ressources/analyseurxml/"
)
add_dependencies(analyseurxml extern_make)

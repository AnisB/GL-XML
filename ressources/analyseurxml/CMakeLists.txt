#add_custom_target(
 #  extern_make
 #	  COMMAND make
 #  WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}/ressources/analyseurxml/"
#
#add
#add_dependencies(analyseurxml extern_make)

if(UNIX)
  add_definitions(`${PROJECT_SOURCE_DIR}/ressources/analyseurxml/makefile`)
endif()
MACRO(BISON_FLEX_BINARY PATATE SDIR BDIR FLEX_FILE BISON_FILE OUTPUT_BISON SOURCE_DIR  )

BISON_TARGET(Parser ${BISON_FILE} ${OUTPUT_BISON} COMPILE_FLAGS " -p xml")
FLEX_TARGET(Scanner ${FLEX_FILE}  ${BDIR}/lex.xml.c COMPILE_FLAGS "-Pxml")
ADD_FLEX_BISON_DEPENDENCY( Scanner Parser)

include_directories(${PROJECT_SOURCE_DIR}/ressources/analyseurxml/)



file(GLOB_RECURSE 
	LIST_SOURCE 
	${SOURCE_DIR}/*
   )

file(GLOB_RECURSE 
	SDIR 
	${FOO_DIR}/*
   )


add_executable(${PATATE}  ${FOO_DIR} ${LIST_SOURCE} ${BISON_Parser_OUTPUTS} ${FLEX_Scanner_OUTPUTS})


target_link_libraries(${PATATE} ${FLEX_LIBRARIES} ${BISON_LIBRARIES})

set(CMAKE_CXX_COMPILER_INIT g++)


if (APPLE)

  set (CMAKE_CXX_COMPILER "/usr/bin/g++" )

endif ()
  ADD_DEFINITIONS(" -g -DYYDEBUG=1 -x c++")
endMACRO()
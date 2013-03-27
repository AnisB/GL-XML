MACRO(BISON_FLEX_BINARY PATATE SOURCE BDIR FLEX_FILE BISON_FILE OUTPUT_BISON SOURCE_DIR  )

BISON_TARGET(Parser ${BISON_FILE} ${OUTPUT_BISON} COMPILE_FLAGS " -p xml")
FLEX_TARGET(Scanner ${FLEX_FILE}  ${BDIR}/lex.xml.c COMPILE_FLAGS "-Pxml")
ADD_FLEX_BISON_DEPENDENCY( Scanner Parser)

include_directories(${PROJECT_SOURCE_DIR}/ressources/analyseurxml/)



file(GLOB_RECURSE 
	LIST_SOURCE 
	${SOURCE_DIR}/*
   )

add_executable(${PATATE}  ${SOURCE} ${LIST_SOURCE} ${BISON_Parser_OUTPUTS} ${FLEX_Scanner_OUTPUTS})


target_link_libraries(${PATATE} ${FLEX_LIBRARIES} ${BISON_LIBRARIES})


endMACRO()

MACRO(BISON_FLEX_FILES EXEC_FILE SOURCE FLEX_FILE BISON_FILE OUTPUT_FLEX OUTPUT_BISON BISON_OPTION FLEX_OPTION SOURCE_DIR )

BISON_TARGET(Parser ${BISON_FILE} ${OUTPUT_BISON} COMPILE_FLAGS ${BISON_OPTION})
FLEX_TARGET(Scanner ${FLEX_FILE}  ${OUTPUT_FLEX} COMPILE_FLAGS ${FLEX_OPTION})
ADD_FLEX_BISON_DEPENDENCY( Scanner Parser)

include_directories(${SOURCE})

file(GLOB_RECURSE 
	LIST_SOURCE 
	${SOURCE_DIR}/*
   )

add_executable(${EXEC_FILE}  ${SOURCE} ${LIST_SOURCE} ${BISON_Parser_OUTPUTS} ${FLEX_Scanner_OUTPUTS})


endMACRO()




MACRO(BISON_FLEX_NOEXEC SOURCE FLEX_FILE BISON_FILE OUTPUT_FLEX OUTPUT_BISON BISON_OPTION FLEX_OPTION SOURCE_DIR )

BISON_TARGET(Parser ${BISON_FILE} ${OUTPUT_BISON} COMPILE_FLAGS ${BISON_OPTION})
FLEX_TARGET(Scanner ${FLEX_FILE}  ${OUTPUT_FLEX} COMPILE_FLAGS ${FLEX_OPTION})
ADD_FLEX_BISON_DEPENDENCY( Scanner Parser)

include_directories(${SOURCE})

file(GLOB_RECURSE 
	LIST_SOURCE 
	${SOURCE_DIR}/*
   )

endMACRO()




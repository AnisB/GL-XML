BISON_FLEX_NOEXEC (
${PROJECT_SOURCE_DIR}/src/parse/dtd/ 
${PROJECT_SOURCE_DIR}/src/parse/dtd/dtd.l 
${PROJECT_SOURCE_DIR}/src/parse/dtd/dtd.y 
${CMAKE_CURRENT_BINARY_DIR}/lex.dtd.c
${CMAKE_CURRENT_BINARY_DIR}/dtd.tab.c 
"-p dtd"
"-Pdtd"
${PROJECT_SOURCE_DIR}/src/dtd/ )

BISON_FLEX_NOEXEC (
${PROJECT_SOURCE_DIR}/src/parse/xml/ 
${PROJECT_SOURCE_DIR}/src/parse/xml/xml.l 
${PROJECT_SOURCE_DIR}/src/parse/xml/xml.y 
${CMAKE_CURRENT_BINARY_DIR}/lex.xml.c
${CMAKE_CURRENT_BINARY_DIR}/xml.tab.c 
"-p xml"
"-Pxml"
${PROJECT_SOURCE_DIR}/src/xml/ )

include_directories(${PROJECT_SOURCE_DIR}/src/)

file(
	GLOB_RECURSE 
	Source_File
	${PROJECT_SOURCE_DIR}/src/xml/* 
	${PROJECT_SOURCE_DIR}/src/dtd/* 
	${PROJECT_SOURCE_DIR}/src/parse/* 
	${PROJECT_SOURCE_DIR}/src/xsl/* 
    )


add_executable(xslsample ${PROJECT_SOURCE_DIR}/test/xslsample/xslsample.cpp ${CMAKE_CURRENT_BINARY_DIR}/xml.tab.c ${CMAKE_CURRENT_BINARY_DIR}/lex.xml.c 
${CMAKE_CURRENT_BINARY_DIR}/lex.dtd.c ${CMAKE_CURRENT_BINARY_DIR}/dtd.tab.c ${Source_File})
target_link_libraries (xslsample ${Boost_REGEX_LIBRARY})
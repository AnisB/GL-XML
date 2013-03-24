BISON_FLEX_NOEXEC (
	${PROJECT_SOURCE_DIR}/src/parse/dtd/ 
	${PROJECT_SOURCE_DIR}/src/parse/dtd/dtd.l 
	${PROJECT_SOURCE_DIR}/src/parse/dtd/dtd.y 
	${PROJECT_BINARY_DIR}/program/processer/lex.dtd.c
	${PROJECT_BINARY_DIR}/program/processer/dtd.tab.c 
	"-p dtd"
	"-Pdtd"
${PROJECT_SOURCE_DIR}/src/dtd/ )

BISON_FLEX_NOEXEC (
	${PROJECT_SOURCE_DIR}/src/parse/xml/ 
	${PROJECT_SOURCE_DIR}/src/parse/xml/xml.l 
	${PROJECT_SOURCE_DIR}/src/parse/xml/xml.y 
	${PROJECT_BINARY_DIR}/program/processer/lex.xml.c
	${PROJECT_BINARY_DIR}/program/processer/xml.tab.c 
	"-p xml"
	"-Pxml"
${PROJECT_SOURCE_DIR}/src/xml/ )

include_directories(${PROJECT_SOURCE_DIR}/src/xml/ ${PROJECT_SOURCE_DIR}/src/dtd/ ${PROJECT_SOURCE_DIR}/src/parse/*)

file(
	GLOB_RECURSE 
	Source_File
	${PROJECT_SOURCE_DIR}/src/xml/* 
	${PROJECT_SOURCE_DIR}/src/dtd/* 
	${PROJECT_SOURCE_DIR}/src/parse/* 
	${PROJECT_SOURCE_DIR}/src/xsl/* 
)


add_executable(processer main.cpp ${PROJECT_BINARY_DIR}/program/processer/xml.tab.c ${PROJECT_BINARY_DIR}/program/processer/lex.xml.c 
${PROJECT_BINARY_DIR}/program/processer/lex.dtd.c ${PROJECT_BINARY_DIR}/program/processer/dtd.tab.c ${Source_File})
target_link_libraries (processer      ${Boost_PROGRAM_OPTIONS_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_REGEX_LIBRARY})
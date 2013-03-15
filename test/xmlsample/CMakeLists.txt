file(
	GLOB_RECURSE 
	Source_File
	${PROJECT_SOURCE_DIR}/src/xml/* 
	#${PROJECT_SOURCE_DIR}/src/dtd/* 
    )


add_executable(xmlsample xmlsample.cpp ${Source_File})
target_link_libraries (xmlsample)
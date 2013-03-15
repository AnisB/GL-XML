file(
	GLOB_RECURSE 
	Source_File
	${PROJECT_SOURCE_DIR}/src/dtd/* 
    )


add_executable(dtdsample dtdsample.cpp ${Source_File})
target_link_libraries (dtdsample)
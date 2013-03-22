#CMakeLists associated to the tests subdir

include_directories (${PROJECT_BINARY_DIR}/src/)

# Make sure the compiler can find include files.
include_directories (${PROJECT_SOURCE_DIR}/tests/)
include_directories (${PROJECT_BINARY_DIR}/tests/)

# Make sure the compiler can find include files of dependencies.
include_directories (${XmlProcessLib})

# Make sure the linker can find the Hello library once it is built.
link_directories (${PROJECT_BINARY_DIR})


#------TESTS subdirectories ------
add_subdirectory(xmlsample)
#add_subdirectory(dtdsample)
#add_subdirectory(<yourdirectory>)





add_executable(option main.cpp)

message(LINK ${XmlProcesserLib}) 
target_link_libraries (option ${XmlProcesserLib})
BISON_FLEX_BINARY ( xslsample
${CMAKE_CURRENT_SOURCE_DIR}/xslsample.cpp 
${CMAKE_CURRENT_BINARY_DIR}/
${PROJECT_SOURCE_DIR}/src/parse/xml/xml.l 
${PROJECT_SOURCE_DIR}/src/parse/xml/xml.y 
${CMAKE_CURRENT_BINARY_DIR}/xml.tab.c 
${PROJECT_SOURCE_DIR}/src/*  )
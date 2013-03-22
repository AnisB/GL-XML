BISON_FLEX_BINARY ( verification
${PROJECT_SOURCE_DIR}/program/verification/main.cpp 
  ${PROJECT_BINARY_DIR}/program/verification/ 
${PROJECT_SOURCE_DIR}/src/parse/xml/xml.l 
${PROJECT_SOURCE_DIR}/src/parse/xml/xml.y 
${PROJECT_BINARY_DIR}/program/verification/xml.tab.c 
${PROJECT_SOURCE_DIR}/src/xml/  )
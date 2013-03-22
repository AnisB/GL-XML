set (SRC  
  ${PROJECT_SOURCE_DIR}/src/xml/xmldocument.cpp 
  ${PROJECT_SOURCE_DIR}/src/xml/xmlcontent.cpp 
  ${PROJECT_SOURCE_DIR}/src/xml/xmlattribute.cpp 
  ${PROJECT_SOURCE_DIR}/src/xml/pcdata.cpp 
  ${PROJECT_SOURCE_DIR}/src/xml/misc.cpp 
  ${PROJECT_SOURCE_DIR}/src/xml/element.cpp 
  )

BISON_FLEX_BINARY (${PROJECT_SOURCE_DIR}/ressources/analyseurxml/ ${PROJECT_BINARY_DIR}/ressources/analyseurxml/ ${PROJECT_SOURCE_DIR}/ressources/analyseurxml/xml.l ${PROJECT_SOURCE_DIR}/ressources/analyseurxml/xml.y ${PROJECT_BINARY_DIR}/ressources/analyseurxml/xml.tab.c ${PROJECT_SOURCE_DIR}/src/xml/ DEBUG )
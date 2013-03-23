BISON_FLEX_FILES ( testdtd
${PROJECT_SOURCE_DIR}/ressources/analyseurdtd/ 
${PROJECT_SOURCE_DIR}/ressources/analyseurdtd/dtd.l 
${PROJECT_SOURCE_DIR}/ressources/analyseurdtd/dtd.y 
  ${PROJECT_BINARY_DIR}/ressources/analyseurdtd/lex.dtd.c
${PROJECT_BINARY_DIR}/ressources/analyseurdtd/dtd.tab.c 
"-p dtd"
"-Pdtd"
${PROJECT_SOURCE_DIR}/src/dtd/ )

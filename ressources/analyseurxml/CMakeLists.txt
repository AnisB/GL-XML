# Create target for the parser
 ADD_CUSTOM_TARGET(Parser echo "Creating parser.c")

# Create custom command for flex/lex (note the outputs)
 ADD_CUSTOM_COMMAND(
   SOURCE ${Project_SOURCE_DIR}/ressources/analyseurxml/xml.l
   COMMAND ${FLEX_EXECUTABLE} 
   ARGS -o${Project_SOURCE_DIR}/ressources/analyseurxml/xml.tabs.c
        ${Project_SOURCE_DIR}/ressources/analyseurxml/xml.l
   TARGET Parser
   OUTPUTS ${Project_SOURCE_DIR}/ressources/analyseurxml/xml.tabs.c)

# Create custom command for bison/yacc (note the DEPENDS)
 ADD_CUSTOM_COMMAND(
   SOURCE ${Project_SOURCE_DIR}/ressources/analyseurxml/xml.y
   COMMAND ${BISON_EXECUTABLE} 
   ARGS -y ${Project_SOURCE_DIR}/ressources/analyseurxml/xml.y
        -o ${Project_SOURCE_DIR}/ressources/analyseurxml/xml.c
   TARGET Parser
   DEPENDS ${Project_SOURCE_DIR}/ressources/analyseurxml/xml.tabs.c
   OUTPUTS ${Project_SOURCE_DIR}/ressources/analyseurxml/xml.c)

# Add parser.c to the list of sources
 SET(Foo_SRCS ${Foo_SRCS} ${Project_SOURCE_DIR}/ressources/analyseurxml/xml.c)

# Since parser.c does not exists yet when cmake is run, mark
# it as generated
 SET_SOURCE_FILES_PROPERTIES(${Project_BINARY_DIR}/ressources/analyseurxml/ GENERATED)

# Include binary directory to include lexer.c in parser.c
 INCLUDE_DIRECTORIES(${Project_SOURCE_DIR}/src/ ${Project_SOURCE_DIR}/ressources/analyseurxml/)
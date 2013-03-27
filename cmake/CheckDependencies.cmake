# -----------------------------------------------------------------------------
# Check Mandatory Dependencies
# -----------------------------------------------------------------------------

# -----------------------------------------------------------------------------
# Look for boost 
# -----------------------------------------------------------------------------
set(Boost_USE_STATIC_LIBS   OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
set(Boost_FOUND FALSE)
FIND_PACKAGE(Boost 1.50.0 REQUIRED program_options regex)
if ( Boost_FOUND )
  message(STATUS "Boost and boost components found.")
  SET(IncDir ${IncDir} ${Boost_INCLUDE_DIRS})
  include_directories( ${Boost_INCLUDE_DIRS})
  SET(Libs ${Libs} 
     ${Boost_LIBRAIRIES}  
     ${Boost_PROGRAM_OPTIONS_LIBRARY}
 ${Boost_REGEX_LIBRARY})
   SET(XmlProcesserLib      ${Boost_REGEX_LIBRARY}  
     ${Boost_PROGRAM_OPTIONS_LIBRARY} )
endif( Boost_FOUND )

find_package(BISON)
find_package(FLEX)
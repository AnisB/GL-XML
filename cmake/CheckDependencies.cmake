# -----------------------------------------------------------------------------
# Check Mandatory Dependencies
# -----------------------------------------------------------------------------

# -----------------------------------------------------------------------------
# Look for boost 
# -----------------------------------------------------------------------------
set(Boost_USE_STATIC_LIBS   ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
set(Boost_FOUND FALSE)
FIND_PACKAGE(Boost 1.42.0 REQUIRED COMPONENTS program_options system)
if ( Boost_FOUND )
  message(STATUS "Boost and boost components found.")
  SET(IncDir ${IncDir} ${Boost_INCLUDE_DIRS})
  include_directories( ${Boost_INCLUDE_DIRS})
  SET(Libs ${Libs} 
     ${Boost_LIBRAIRIES}  
     ${Boost_PROGRAM_OPTIONS_LIBRARY}
     ${Boost_SYSTEM_LIBRARY})
   SET(DGtalLibInc ${Boost_INCLUDE_DIRS})
endif( Boost_FOUND )


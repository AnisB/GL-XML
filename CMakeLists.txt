# -----------------------------------------------------------------------------
# Project definition
# -----------------------------------------------------------------------------
project (XmlProcesser)
cmake_minimum_required (VERSION 2.6) 

# By default, do not warn when built on machines using only VS Express:
IF(NOT DEFINED CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS_NO_WARNINGS)
    SET(CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS_NO_WARNINGS ON)
ENDIF()

# -----------------------------------------------------------------------------
# Define variables and cmake parameters, and display some information
# -----------------------------------------------------------------------------
SET(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
# -----------------------------------------------------------------------------
# Common build options/settings
# -----------------------------------------------------------------------------
#INCLUDE(${CMAKE_MODULE_PATH}/Common.cmake)

# -----------------------------------------------------------------------------
# Check Mandatory Dependencies
# -----------------------------------------------------------------------------
INCLUDE(${CMAKE_MODULE_PATH}/CheckDependencies.cmake)
INCLUDE(${CMAKE_MODULE_PATH}/macro.cmake)

if (doc)
	INCLUDE(${CMAKE_MODULE_PATH}/dox.cmake)
endif(doc)
set(IncDir "${PROJECT_SOURCE_DIR}/src; ${IncDir}; ")
include_directories( ${IncDir})


#------------------------------------------------------------------------------
# Add subdirectories
#------------------------------------------------------------------------------
add_subdirectory(src)
add_subdirectory(program)
if(test)
	add_subdirectory(test)
endif(test)

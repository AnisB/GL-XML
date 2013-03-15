cmake_minimum_required(VERSION 2.6)

project(xmlprocesser)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMake/;${CMAKE_MODULE_PATH}")
message(STATUS "${CMAKE_MODULE_PATH}")
 

message(STATUS "Looking for boost")
#  Boost finding
set(Boost_ADDITIONAL_VERSIONS "1.44" "1.44.0" "1.42" "1.42.0" "1.41.0" "1.41" "1.40.0" "1.40" "1.39.0" "1.39" "1.38.0" "1.38" "1.37.0" "1.37" )
set(OGRE_BOOST_COMPONENTS thread date_time)
find_package(Boost COMPONENTS ${OGRE_BOOST_COMPONENTS} QUIET)
if (NOT Boost_FOUND)
	# Try again with the other type of libs
	set(Boost_USE_STATIC_LIBS NOT ${Boost_USE_STATIC_LIBS})
	find_package(Boost COMPONENTS ${OGRE_BOOST_COMPONENTS} QUIET)
endif()
find_package(Boost QUIET)
	include_directories(${Boost_INCLUDE_DIR})
add_definitions(-DBOOST_ALL_NO_LIB)
set(OGRE_LIBRARIES ${OGRE_LIBRARIES} ${Boost_LIBRARIES})

 
 
file(
	GLOB_RECURSE 
	Source_Files 
	${PROJECT_SOURCE_DIR}/src/* 
    )
 
 
  include_directories( 
  ${PROJECT_SOURCE_DIR}/src/xml
  ${PROJECT_SOURCE_DIR}/src/dtd
    )

add_executable(xmlprocesser ${Source_File})

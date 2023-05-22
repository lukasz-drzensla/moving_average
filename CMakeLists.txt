cmake_minimum_required( VERSION 3.6.2 )

set( PROJECT_NAME moving_average )

project( ${PROJECT_NAME} )

set( CMAKE_BUILD_TYPE Debug )
#set( CMAKE_BUILD_TYPE Release )

if( WIN32 )
	set( CMAKE_CXX_FLAGS "/DWIN32 /D_WINDOWS /W3 /GR /EHsc /std:c++20 /D_UNICODE /DUNICODE" )
	set( CMAKE_CXX_FLAGS_DEBUG "/MDd /Zi /Ob0 /Od /RTC1 /std:c++20 /D_UNICODE /DUNICODE" )
elseif( ${CMAKE_SYSTEM_NAME} STREQUAL "Darwin" )
	set( CMAKE_CXX_FLAGS "-std=c++20 -Wall" )
	set( CMAKE_CXX_FLAGS_DEBUG "-g -std=c++20 -Wall" )
elseif( UNIX )
	set( CMAKE_CXX_FLAGS "-std=c++20 -Wall" )
	set( CMAKE_CXX_FLAGS_DEBUG "-g -std=c++20 -Wall" )
endif()

include_directories( include )

file ( GLOB SOURCES "*.h" "*.c")
add_executable( ${PROJECT_NAME} ${SOURCES} )

set_property( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME} )

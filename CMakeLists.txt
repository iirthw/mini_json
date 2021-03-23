cmake_minimum_required( VERSION 3.19 )

set( CMAKE_CXX_STANDARD 14 )
set( PROJ_NAME "mini_json" )
project( ${PROJ_NAME} )

add_subdirectory( lib )
add_subdirectory( test )
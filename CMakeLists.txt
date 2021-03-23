cmake_minimum_required( VERSION 3.19 )

set( CMAKE_CXX_STANDARD 14 )
set( PROJ_NAME "mini_json" )
project( ${PROJ_NAME} )

# According to the cmake documentation
# https://cmake.org/cmake/help/latest/command/enable_testing.html
# enable_testing command should be at the directory root
enable_testing()

add_subdirectory( lib )
add_subdirectory( test )
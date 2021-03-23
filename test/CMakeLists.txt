# temporarily hard-coded TEST_TARGET (runs unit tests) always ON
# Set to OFF if it is desirable to omit test target
set( TEST_TARGET ON )
if ( NOT TEST_TARGET ) 
	include( ${PROJECT_SOURCE_DIR}/cmake/tests_disabled.cmake )
	return()
endif() # if (TEST_TARGET)

include( ${PROJECT_SOURCE_DIR}/cmake/tests_enabled.cmake )
include( ${PROJECT_SOURCE_DIR}/cmake/find_gtest.cmake )

add_subdirectory(test_json)
# Refer to GTest boiler-plate code examples
# such as
# https://github.com/kaizouman/gtest-cmake-example/blob/master/test/CMakeLists.txt

set( GTEST_ENABLED OFF ) # temporarily hard-coded always ON
if ( NOT GTEST_ENABLED ) 
	include( ${PROJECT_SOURCE_DIR}/cmake/test_runner_disabled.cmake )
	return()
endif() # if (GTEST_ENABLED)	

include( ${PROJECT_SOURCE_DIR}/cmake/test_runner_enabled )

set( TEST_RUNNER_TARGET "RunTests" )

enable_testing()
find_package( GTest REQUIRED )

if ( NOT GTEST_FOUND )
	message( "/!\ GTest not found\n" )
endif() # 

add_executable( ${TEST_RUNNER_TARGET} "json_test.cpp" ) 
target_link_libraries( foo GTest::gtest GTest::gtest_main )

	# add_test(AllTestsInFoo foo)

# Use the following to finish setting up Gtest:
# https://github.com/google/googletest/blob/master/googletest/README.md
# https://stackoverflow.com/questions/8507723/how-to-start-working-with-gtest-and-cmake
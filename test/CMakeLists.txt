# Refer to GTest boiler-plate code examples
# such as
# https://github.com/kaizouman/gtest-cmake-example/blob/master/test/CMakeLists.txt

set( TEST_MODULE OFF ) # temporarily hard-coded always ON
if ( NOT TEST_MODULE ) 
	include( ${PROJECT_SOURCE_DIR}/cmake/test_module_disabled.cmake )
	return()
endif() # if (TEST_MODULE)

include( ${PROJECT_SOURCE_DIR}/cmake/test_module_enabled )

set( TEST_MODULE_TARGET "TestModule" )

# According to the cmake documentation
# https://cmake.org/cmake/help/latest/command/enable_testing.html
# enable_testing command should be at the directory root
enable_testing()

find_package( GTest REQUIRED )

add_executable( ${TEST_RUNNER_TARGET} "json_test.cpp" ) 
target_link_libraries( foo GTest::gtest GTest::gtest_main )

	# add_test(AllTestsInFoo foo)

# Use the following to finish setting up Gtest:
# https://github.com/google/googletest/blob/master/googletest/README.md
# https://stackoverflow.com/questions/8507723/how-to-start-working-with-gtest-and-cmake
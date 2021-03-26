# temporarily hard-coded TEST_TARGET (runs unit tests) always ON
# Set to OFF if it is desirable to omit test target
set(TEST_TARGET ON)

if (NOT TEST_TARGET) 
	include(${PROJECT_SOURCE_DIR}/cmake/log_tests_disabled.cmake)
else()
    include(${PROJECT_SOURCE_DIR}/cmake/log_tests_enabled.cmake)
    include(${PROJECT_SOURCE_DIR}/cmake/configure_gtest.cmake)

    add_subdirectory(test_json)
endif()
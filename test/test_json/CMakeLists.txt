project(RunUnitTests)

set(SOURCE_FILES test_json.cpp)

add_executable(${PROJECT_NAME} main.cpp ${SOURCE_FILES})
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} 
        PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

get_target_property(LIBRARY_INCLUDES ${CMAKE_PROJECT_NAME} INCLUDE_DIRECTORIES)
target_include_directories(${PROJECT_NAME}
                        PUBLIC
                        ${LIBRARY_INCLUDES})

target_link_libraries(${PROJECT_NAME} ${CMAKE_PROJECT_NAME} gtest)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
# Consider using test properties to pass a WORKING_DIR, for instance
# set_tests_properties(mytests PROPERTIES
#        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests)

message("Copying test resources")
message(${CMAKE_CURRENT_SOURCE_DIR}/resources/simple.json)
message("to \n" ${CMAKE_CURRENT_BINARY_DIR}/resources/simple.json)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/resources/simple.json 
    ${CMAKE_CURRENT_BINARY_DIR}/resources/simple.json COPYONLY)
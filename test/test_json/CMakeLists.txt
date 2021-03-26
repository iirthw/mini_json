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
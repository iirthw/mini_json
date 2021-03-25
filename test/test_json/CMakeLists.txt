set ( TEST_JSON test_json)

set(SRCS test_json.cpp )
add_executable( ${TEST_JSON} main.cpp ${SRCS} )

target_include_directories( ${TEST_JSON} 
                            PUBLIC
                            ${PROJECT_SOURCE_DIR}/lib/public )
target_link_libraries( ${TEST_JSON}
			           ${MINI_JSON_LIB} 
                       gtest )

add_test(NAME ${TEST_JSON} COMMAND ${TEST_JSON})
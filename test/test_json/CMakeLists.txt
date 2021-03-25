set ( TEST_JSON test_json)

set(SRCS test_json.cpp )
add_executable( ${TEST_JSON} main.cpp ${SRCS} )

get_target_property(MINI_JSON_INCLUDES "mini_json" INCLUDE_DIRECTORIES)
target_include_directories( ${TEST_JSON} 
                            PUBLIC
                            ${MINI_JSON_INCLUDES} )

target_link_libraries( ${TEST_JSON}
			           ${MINI_JSON_LIB} 
                       gtest )

add_test(NAME ${TEST_JSON} COMMAND ${TEST_JSON})
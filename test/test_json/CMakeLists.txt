set ( TEST_JSON test_json)

set(SRCS test_json.cpp )
add_executable( ${TEST_JSON} main.cpp ${SRCS} )
target_link_libraries( ${TEST_JSON}
			 ${MINI_JSON_LIB}
			 libgtest
)

add_test(NAME ${TEST_JSON} COMMAND ${TEST_JSON})
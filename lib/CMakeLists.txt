set(HEADER_FILES public/json.h public/string_utils.h)
set(IMPL_FILES impl/json.cpp impl/string_utils.cpp)
set(SOURCE_FILES ${HEADER_FILES} ${IMPL_FILES})

add_library(${CMAKE_PROJECT_NAME} STATIC ${SOURCE_FILES})
target_include_directories(${CMAKE_PROJECT_NAME} 
	                    PUBLIC
	                    ${CMAKE_CURRENT_SOURCE_DIR}/public
	                    )
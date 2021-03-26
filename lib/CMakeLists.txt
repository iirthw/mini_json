set(HEADER_FILES public/json.h)
set(IMPL_FILES impl/json.cpp)
set(SOURCE_FILES ${HEADER_FILES} ${IMPL_FILES})

add_library(${CMAKE_PROJECT_NAME} STATIC ${SOURCE_FILES})
target_include_directories(${CMAKE_PROJECT_NAME} 
	                       PUBLIC
	                       ${CMAKE_CURRENT_SOURCE_DIR}/public
	                       )
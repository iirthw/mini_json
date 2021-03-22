cmake_minimum_required (VERSION 3.15)
set (PROJECT_NAME "mini_json")
project (${PROJECT_NAME})

set (CMAKE_CXX_STANDARD 14)

target_sources (${PROJECT_NAME}
	PUBLIC
	src/json.h
	src/json.cpp)

if( MY_VARIABLE ) 
    message("MY_VARIABLE evaluates to True")
endif()
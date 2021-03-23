set( LIB_NAME mini_json)
set( LIB_HEADER_FILES src/json.h )
set( LIB_IMPL_FILES src/json.cpp )
set( LIB_SOURCE_FILES 
	${LIB_HEADER_FILES} 
	${LIB_IMPL_FILES}
	)
message( ${LIB_SOURCE_FILES} )

add_library( ${LIN_NAME} STATIC ${LIB_SOURCE_FILES} )

# include direcories exported by the library
target_include_directories( ${LIB_NAME} 
	${CMAKE_CURRENT_SOURCE_DIR}/src 
	)
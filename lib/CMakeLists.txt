set( MINI_JSON_LIB mini_json)
set( LIB_HEADER_FILES src/json.h )
set( LIB_IMPL_FILES src/json.cpp )
set( LIB_SOURCE_FILES 
	${LIB_HEADER_FILES}
	${LIB_IMPL_FILES}
	)

add_library( ${MINI_JSON_LIB} STATIC ${LIB_SOURCE_FILES} )

# include direcories exported by the library
target_include_directories( ${MINI_JSON_LIB} 
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/src 
	)
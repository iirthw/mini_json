get_filename_component(CURR_CMAKE_FILE_NAME ${CMAKE_CURRENT_LIST_FILE} NAME)

message( "+-------------------------------+" )
message( "| Processing " ${CURR_CMAKE_FILE_NAME} "   |")
message( "+-------------------------------+" )

# GoogleTest must be already installed as a standalone project
# (in such case GTEST_ROOT variable must be defined)
# or it can be incorporated into an existing CMake build 
# (define GTEST_FORCE_EXTERNAL for the latter option)
if ( NOT DEFINED GTEST_ROOT AND NOT DEFINED ENV{GTEST_ROOT})
	message( 
		"+-----------------------------------------------------------------------------------------+\n"
		"/!\\ Warning /!\\ \n"
		"GTEST_ROOT is not defined. From now there are three options:\n"
		"1. Specify GTEST_ROOT when running cmake, like this: 'cmake -DGTEST_ROOT=FooBar ... '\n"
		"2. Configure GTEST_ROOT environment variable (see how environmet vars are defined on your OS) \n" 
		"3. Enable GTEST_FORCE_EXTERNAL, like this: 'cmake -DGTEST_FORCE_EXTERNAL ... '\n"
		"+-----------------------------------------------------------------------------------------+\n"
		)
	return()
elseif ( NOT DEFINED GTEST_ROOT AND DEFINED ENV{GTEST_ROOT} )
	message( "Use environment variable " ENV{GTEST_ROOT} )
	set( GTEST_ROOT ENV{GTEST_ROOT} )

	set( FIND_GTEST TRUE )
elseif ( DEFINED GTEST_ROOT )
	set( FIND_GTEST TRUE )
endif()

if ( ${FIND_GTEST} )
	find_package( GTest REQUIRED )

	if ( NOT GTEST_FOUND )
		message( FATAL_ERROR "GoogleTest not found" )
	endif()

	include_directories( ${GTEST_INCLUDE_DIRS} )
endif()

if ( DEFINED GTEST_FORCE_EXTERNAL )
	# this module is required for ExternalProject_Add
	include( ExternalProject )
	# Download GTest source and add it as an external project to the current target
	ExternalProject_Add(
    	gtest
    	URL https://github.com/google/googletest/archive/master.zip
    	PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
    	# Disable install step
    	INSTALL_COMMAND ""
    )

    # Get GTest source and binary directories from CMake project
    ExternalProject_Get_Property(gtest source_dir binary_dir)

    # Create a libgtest target to be used as a dependency by test programs
    add_library( libgtest IMPORTED STATIC GLOBAL )
    add_dependencies( libgtest gtest )

    # Set libgtest properties
    set_target_properties( libgtest 
    					   PROPERTIES
    					   "IMPORTED_LOCATION" "${binary_dir}/googlemock/gtest/libgtest.a"
    					   "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
    					 )

    include_directories("${source_dir}/googletest/include"
    	                "${source_dir}/googlemock/include")
endif() # DEFINED GTEST_FORCE_EXTERNAL

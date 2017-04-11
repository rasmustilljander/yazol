# - Find gtest
# Find the native googletest includes and libraries
#
#  GTEST_INCLUDE_PATH - Path to gtest.h.
#  GTEST_LIBRARY_PATH - Path to the library.
#  GTEST_LIBRARIES 	  - List of libraries when using googletest.
#  GTEST_FOUND 		  - True if googletest found.

if(GTEST_INCLUDE_PATH)
	# Already in cache, be silent
	set(GTEST_FIND_QUIETLY TRUE)
endif(GTEST_INCLUDE_PATH)

## Include path
find_path(GTEST_INCLUDE_PATH
		gtest/gtest.h)

## Lib path
find_library(GTEST_LIBRARY_PATH
		NAMES gtest)

# Handle the QUIETLY and REQUIRED arguments and set GTEST_FOUND to TRUE if
# all listed variables are TRUE.
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(GTEST DEFAULT_MSG GTEST_LIBRARY_PATH GTEST_INCLUDE_PATH)

if(GTEST_FOUND)
	set(GTEST_LIBRARIES ${GTEST_LIBRARY_PATH})
else(GTEST_FOUND)
	set(GTEST_LIBRARIES)
endif(GTEST_FOUND)

mark_as_advanced(GTEST_INCLUDE_PATH GTEST_LIBRARY_PATH)
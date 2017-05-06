cmake_minimum_required(VERSION 3.7)

project(yazol)

set(REPOSITORY_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "${REPOSITORY_ROOT}/external/libs/")
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "${REPOSITORY_ROOT}/external/include/")

# Find external libraries and modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMake/Modules/")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_ROOT}/Modules/")
include(create_source_group)

# Require modules
find_package(Gtest REQUIRED)

# Add root as include path
include_directories(${REPOSITORY_ROOT})

# Set compiler option
set(CMAKE_CXX_FLAGS "-g -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

# Set test module naming prefix
set(TEST_SUFFIX _test)

# Get subfolders
add_subdirectory(yazol)
add_subdirectory(yazol_impl)
add_subdirectory(yazol_test)
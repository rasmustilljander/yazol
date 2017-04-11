cmake_minimum_required(VERSION 3.7)

# Root project settings
set(MODULE_NAME yazol)
project(${MODULE_NAME})

# Set the files used in the target
file(GLOB_RECURSE HEADERS Headers/ *.hpp)
file(GLOB_RECURSE SOURCES Source/ *.cpp)

set(INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/hpp/)
set(LIBRARIES )

# Add the target
add_library(${MODULE_NAME} STATIC ${HEADERS} ${SOURCES})
target_include_directories(${MODULE_NAME} PUBLIC "${INCLUDE_DIRECTORIES}")
target_link_libraries(${MODULE_NAME} ${LIBRARIES})
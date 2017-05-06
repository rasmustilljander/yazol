cmake_minimum_required(VERSION 3.7)

# Set names
set(NAME_OF_TEST_MODULE yazol)
set(MODULE_NAME ${NAME_OF_TEST_MODULE}${TEST_SUFFIX})
project(${MODULE_NAME})

# Find files
file(GLOB_RECURSE HEADERS Headers/ *.hpp)
file(GLOB_RECURSE SOURCES Source/ *.cpp)
create_source_group("Header Files" "${CMAKE_CURRENT_SOURCE_DIR}/hpp" ${HEADERS})
create_source_group("Source Files" "${CMAKE_CURRENT_SOURCE_DIR}/cpp" ${SOURCES})

# Set include directories and libraries
set(INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/hpp/)
set(LIBRARIES "${GTEST_LIBRARIES}" ${NAME_OF_TEST_MODULE} pthread)

# Add the target
add_executable(${MODULE_NAME} ${HEADERS} ${SOURCES})
target_link_libraries(${MODULE_NAME} ${LIBRARIES})
target_include_directories(${MODULE_NAME} PUBLIC ${INCLUDE_DIRECTORIES})
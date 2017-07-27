cmake_minimum_required(VERSION 2.8.11)
project(udemy_advanced)

set(GTEST_SUBDIR googletest)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# include_directories(${GTEST_SUBDIR}/googlemock/include)
# include_directories(${GTEST_SUBDIR}/googletest/include)

add_subdirectory(${GTEST_SUBDIR})
add_subdirectory(session_2_exceptions)
add_subdirectory(session_3_files)


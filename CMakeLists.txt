cmake_minimum_required(VERSION 3.1)

set(CMAKE_C_COMPILER gcc-7)
set(CMAKE_CXX_COMPILER g++-7)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS)

project(udemy_advanced)

set(GTEST_SUBDIR googletest)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_subdirectory(${GTEST_SUBDIR})
add_subdirectory(session_2_exceptions)
add_subdirectory(session_3_files)
add_subdirectory(stl_youtube_study)
add_subdirectory(codility_challenge)

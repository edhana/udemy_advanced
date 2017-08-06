cmake_minimum_required(VERSION 2.8.11)
set(TARGET stl_review)

project(${TARGET})

add_executable(${TARGET} stl_review_test.cpp)
target_link_libraries(${TARGET} gtest)

# set gcc configuration
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS)



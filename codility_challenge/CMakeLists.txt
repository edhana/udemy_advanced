cmake_minimum_required(VERSION 2.8.11)
set(TARGET codility)

project(${TARGET})

add_executable(${TARGET} challenge.cpp)
target_link_libraries(${TARGET} gtest)


cmake_minimum_required(VERSION 2.8.11)
set(TARGET session3_files)

project(${TARGET})

add_executable(${TARGET} test_ex5_files.cpp)
target_link_libraries(${TARGET} gtest)


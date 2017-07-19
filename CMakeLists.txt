cmake_minimum_required(VERSION 2.8.11)
set(TARGET cpluplus-test)
set(GTEST_SUBDIR googletest)

project(${TARGET})
add_subdirectory(${GTEST_SUBDIR})

add_executable(ex1 test_ex1_exception.cpp)
target_link_libraries(ex1 gtest)

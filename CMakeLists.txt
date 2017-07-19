cmake_minimum_required(VERSION 2.8.11)
set(TARGET cpluplus-test)
set(GTEST_SUBDIR googletest)

project(${TARGET})
add_subdirectory(${GTEST_SUBDIR})

# exercise 1
add_executable(ex1 test_ex1_exception.cpp)
target_link_libraries(ex1 gtest)

# exercise 2
add_executable(ex2 ex2_standard_exceptions.cpp)
target_link_libraries(ex2 gtest)


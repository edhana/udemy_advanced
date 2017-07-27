cmake_minimum_required(VERSION 2.8.11)
set(TARGET udemy_exeptions)

project(${TARGET})

# link_directories(../${PROJECT_SOURCE_DIR}/lib)

# exercise 1
add_executable(ex1 test_ex1_exception.cpp)
target_link_libraries(ex1 gtest)

# exercise 2
add_executable(ex2 ex2_standard_exceptions.cpp)
target_link_libraries(ex2 gtest)

# exercise 3
add_executable(ex3 ex3_custom_exceptions.cpp)
target_link_libraries(ex3 gtest)

# exercise 4 
add_executable(ex4 ex4_subclass_exception_catching.cpp)
target_link_libraries(ex4 gtest)


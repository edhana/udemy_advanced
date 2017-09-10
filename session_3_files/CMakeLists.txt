cmake_minimum_required(VERSION 2.8.11)
set(TARGET session3)

project(${TARGET})

# GOTCHA: For experimental stuff you need to link against libstdc++fs
add_executable(${TARGET} session3_files.cpp)
target_link_libraries(${TARGET} gtest stdc++fs)

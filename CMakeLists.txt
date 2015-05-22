cmake_minimum_required(VERSION 2.8)
project(Z3_Math)
include_directories(src)

# Get Source List
file(GLOB_RECURSE PROJECT_SOURCES "src/*.cpp")
message(STATUS "${PROJECT_SOURCES}")

add_subdirectory(gtest-1.7.0)
add_subdirectory(src)
add_subdirectory(tests)

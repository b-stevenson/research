# Now build our tools
enable_testing()
include_directories("${gtest_SOURCE_DIR}/include")
message(STATUS "${gtest_SOURCE_DIR}")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g") 

add_executable(testProg z3MathUnitTest.cpp)
target_link_libraries(testProg Z3Math gtest gtest_main)

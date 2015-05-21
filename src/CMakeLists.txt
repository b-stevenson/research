# Set your project compile flags.
# E.g. if using the C++ header files
# you will need to enable C++11 support
# for your compiler.

SET(GCC_COVERAGE_COMPILE_FLAGS "-std=c++11 -g -fPIC -Wall")
SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

# Now build our tools
add_library(Z3Math SHARED z3Math.cpp)



# Link against LLVM libraries
target_link_libraries(Z3Math ssari)

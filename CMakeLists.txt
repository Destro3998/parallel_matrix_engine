cmake_minimum_required(VERSION 3.16)
project(parallel-matrix-engine VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -pthread")

# Library
add_library(matlib
    src/matrix.cpp
    src/threadpool.cpp
)
target_include_directories(matlib PUBLIC include)

# Main executable
add_executable(matrix_engine src/main.cpp)
target_link_libraries(matrix_engine PRIVATE matlib)

# GoogleTest for testing
enable_testing()
find_package(GTest REQUIRED)
add_executable(test_matrix tests/test_matrix.cpp)
target_link_libraries(test_matrix PRIVATE matlib GTest::GTest GTest::Main)
add_test(NAME MatrixTest COMMAND test_matrix)

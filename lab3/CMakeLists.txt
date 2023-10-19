cmake_minimum_required(VERSION 3.11.1)
project(gtest)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab3 main.cpp src/figure.cpp src/square.cpp) #and need more figure

enable_testing()

add_executable(test_fig test/test_figure.cpp src/figure.cpp)
target_link_libraries(test_fig ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND test_fig)

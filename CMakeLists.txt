cmake_minimum_required(VERSION 3.10)
project(oop_lab_2course)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(labNumb1 lab1/main.cpp  lab1/src/eub.cpp)
add_executable(labNumb2 lab2/main.cpp lab2/src/seven.cpp)
add_executable(labNumb3 lab3/main.cpp lab3/src/figure.cpp lab3/src/square.cpp lab3/src/triangle.cpp lab3/src/octagon.cpp lab3/src/arrayFig.cpp)

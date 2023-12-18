cmake_minimum_required(VERSION 3.11.1)
project(gtest)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    lab7 main.cpp 
    src/ClassHeroes/Squirrel.cpp src/ClassHeroes/Druid.cpp src/ClassHeroes/Werewolf.cpp src/ClassHeroes/ClassAndNameHeroes.cpp
    src/Battle.cpp src/FactoryHeroes.cpp src/Heroes.cpp src/Observer.cpp src/FightManager.cpp
)

enable_testing()

add_executable(tests test/test.cpp 
    src/ClassHeroes/Squirrel.cpp src/ClassHeroes/Druid.cpp src/ClassHeroes/Werewolf.cpp src/ClassHeroes/ClassAndNameHeroes.cpp
    src/Battle.cpp src/FactoryHeroes.cpp src/Heroes.cpp src/Observer.cpp src/FightManager.cpp
)
target_link_libraries(tests ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests)
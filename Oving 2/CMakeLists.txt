cmake_minimum_required(VERSION 3.26)
project(Øving_2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_BUILD_TYPE Debug)


# Create an executable for task1
add_executable(Task1 task1.cpp)
add_executable(Task4 task4.cpp)
add_executable(Task5 task5.cpp)
add_executable(Task6 task6.cpp)

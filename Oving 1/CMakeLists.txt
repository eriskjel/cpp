cmake_minimum_required(VERSION 3.26)
project(Eksempler)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")


# Create an executable for main.cpp
add_executable(MainTask b.cpp)

# Create another executable for a.cpp
add_executable(TaskA a.cpp)

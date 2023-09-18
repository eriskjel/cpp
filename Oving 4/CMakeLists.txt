cmake_minimum_required(VERSION 3.5)
project(Oving_4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra -Wno-unused-parameter")

add_executable(Oving_4-1 Task1.cpp)


INCLUDE(FindPkgConfig)

pkg_check_modules(GTKMM gtkmm-3.0 REQUIRED)
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

add_executable(gtkmm_example main.cpp)
target_link_libraries(gtkmm_example ${GTKMM_LIBRARIES})

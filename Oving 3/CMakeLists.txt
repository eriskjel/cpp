cmake_minimum_required(VERSION 3.26)
project(Oving_3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")


add_executable(Circle CircleClient.cpp
        Circle.cpp
        Circle.hpp
        )

add_executable(Commodity
        CommodityClient.cpp
        Commodity.cpp
        Commodity.hpp
)

add_executable(Streng
        Streng.cpp
)





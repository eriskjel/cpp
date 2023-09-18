cmake_minimum_required(VERSION 3.26)
project(Oving_3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")


add_executable(Oving_3 CircleClient.cpp
        Circle.cpp
        Circle.h
        )

add_executable(CommodityClient
        CommodityClient.cpp
        Commodity.cpp
        Commodity.h
)

add_executable(Streng
        Streng.cpp
)





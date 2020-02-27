cmake_minimum_required(VERSION 3.14)
project(clib)

set(CMAKE_CXX_STANDARD 11)

include_directories(
        # kernel headers
        "/usr/local/Cellar/lua/5.3.5_1/include/lua5.3"
)

add_executable(clib main.cpp mylib.c)
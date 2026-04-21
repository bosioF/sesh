cmake_minimum_required(VERSION 3.3)
project(sesh C)

set(CMAKE_C_STANDARD 11)

add_executable(sesh
        src/main.c
        include/config.h
        include/types.h
)

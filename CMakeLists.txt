cmake_minimum_required(VERSION 3.5)
project(sesh C)

set(CMAKE_C_STANDARD 11)

add_executable(sesh
        src/main.c
        src/parsing.c
        include/config.h
        include/types.h
        include/parsing.h
        src/execute.c
        include/execute.h
        src/helpers.c
        include/helpers.h
)

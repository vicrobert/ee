cmake_minimum_required(VERSION 3.26)
project(ee C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(
        ee
        include/list.h
        src/parser.c
        src/operator.c
        src/token.c
        src/result.c
        src/tensor.c
        src/main.c
)

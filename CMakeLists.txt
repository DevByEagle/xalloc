cmake_minimum_required(VERSION 3.10)
project(xalloc)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

add_executable(${PROJECT_NAME} main.c)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
cmake_minimum_required(VERSION 3.10)
project(xalloc)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

file(GLOB SOURCES "*.c" "*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
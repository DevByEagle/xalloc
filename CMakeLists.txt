cmake_minimum_required(VERSION 3.10)
project(xalloc C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

add_executable(${PROJECT_NAME} main.c xalloc.h)

cmake_minimum_required(VERSION 3.10)
project(xalloc)

file(GLOB SOURCES "*.c" "*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

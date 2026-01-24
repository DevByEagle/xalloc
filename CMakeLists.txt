
cmake_minimum_required(VERSION 3.14)
project(xalloc)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
option(BUILD_EXAMPLES "Build the examples" ${PROJECT_IS_TOP_LEVEL})

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(CompilerFlags)

# Add subdirectories
add_subdirectory(src)

if (${BUILD_EXAMPLES})
    add_subdirectory(examples)
endif()
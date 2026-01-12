cmake_minimum_required(VERSION 3.14)
project(xalloc)

option(BUILD_SHARED_LIBS "Build shared libraries" FALSE)
option(XALLOC_BUILD_EXAMPLES "Build example programs" TRUE)

# Add subdirectories
add_subdirectory(src)

if(XALLOC_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
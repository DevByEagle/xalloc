project(examples)

if (NOT TARGET xalloc)
    find_package(xalloc 1.0.0 REQUIRED)
endif()

macro(add_example name)
    add_executable(xalloc_example_${name} ${name}.cpp)
    target_link_libraries(xalloc_example_${name} PRIVATE xalloc)
endmacro()

add_example(allocator_storage)
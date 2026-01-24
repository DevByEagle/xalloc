project(examples)

if (NOT TARGET xalloc)
    find_package(xalloc 1.0.0 REQUIRED)
endif()

macro(add_example source_file)
    get_filename_component(example_name "${source_file}" NAME_WE)

    add_executable(xalloc_example_${example_name}
        ${source_file}
    )

    target_link_libraries(xalloc_example_${example_name} PRIVATE xalloc)
endmacro()

file(GLOB EXAMPLE_SOURCES CONFIGURE_DEPENDS *.cpp)

foreach(example ${EXAMPLE_SOURCES})
    add_example(${example})
endforeach()
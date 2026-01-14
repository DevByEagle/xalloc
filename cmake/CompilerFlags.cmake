set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

if (MSVC)
    add_compile_options(
        /W3
    )

    add_compile_definitions(
        _CRT_SECURE_NO_WARNINGS
    )
else()
    add_compile_options(
        -Wall 
        -Wextra 
        -Wconversion 
        -Wsign-conversion
    )
endif()
set(header_path ${CMAKE_SOURCE_DIR}/include/xalloc)
file(GLOB HEADERS "${header_path}/*.h")
file(GLOB SOURCES "*.cpp")

add_library(xalloc ${HEADERS} ${SOURCES})
target_include_directories(xalloc PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/> # for client in subdirectory
                                         $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}> # for generated files in build mode
                                  PRIVATE ${header_path})  # for source files


if (BUILD_SHARED_LIBS)
    set_property(TARGET xalloc PROPERTY POSITION_INDEPENDENT_CODE ON)
endif()
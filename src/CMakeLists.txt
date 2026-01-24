file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*cpp)

add_library(xalloc ${SOURCES} ${HEADERS})

if (BUILD_SHARED_LIBS)
    set_property(TARGET xalloc PROPERTY POSITION_INDEPENDENT_CODE ON)
endif()

target_include_directories(xalloc
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/>
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include/xalloc
)
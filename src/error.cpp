#include "error.h"

const char* xalloc::out_of_memory::what() const noexcept
{
    return "low-level allocator is out of memory";
}
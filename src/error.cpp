#include "error.h"

namespace xalloc
{
    const char* out_of_memory::what() const noexcept
    {
        return "low-level allocator is out of memory";
    }
}
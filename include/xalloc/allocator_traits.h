#pragma once

#include <type_traits>

#include "xalloc.h"

namespace xalloc
{
    template <class Allocator>
    class allocator_traits
    {
    public:
        using allocator_type = typename std::decay<void>::type;
    };
}
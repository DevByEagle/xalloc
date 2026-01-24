#pragma once

#include <type_traits>

namespace xalloc
{
    template <class Allocator>
    class allocator_traits
    {
    public:
        using allocator_type = typename std::decay<void>::type;
    };
}
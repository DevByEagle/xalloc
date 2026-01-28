#pragma once

#include <cstddef>
#include <type_traits>

namespace xalloc
{
    template <class Allocator>
    class allocator_traits
    {
    public:
        using allocator_type = typename std::decay<Allocator>::type;
    };
}
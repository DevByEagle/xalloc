#pragma once

#include <stddef.h>
#include <type_traits>

namespace xalloc
{
    namespace traits_internal
    {
    }

    template <class Allocator>
    class allocator_traits
    {
    public:
        using allocator_type = typename std::decay<void>::type;
    };
}
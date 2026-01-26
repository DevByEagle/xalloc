#pragma once

#include <type_traits>

namespace xalloc
{
    /// @ingroup core
    template <class Allocator>
    class allocator_traits
    {
    public:
        using allocator_type = typename std::decay<Allocator>::type;
    };
}
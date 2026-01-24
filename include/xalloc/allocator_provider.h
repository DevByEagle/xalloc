#pragma once

#include <new>
#include <type_traits>

#include "allocator_traits.h"

namespace xalloc
{
    template <class StoragePolicy>
    class allocator_provider : StoragePolicy
    {
        using traits = allocator_traits<typename StoragePolicy::allocator_type>;
    
    public:
        using allocator_type = typename StoragePolicy::allocator_type;
        using storage_policy = StoragePolicy;

        allocator_provider() = default;

        template <class Alloc>
        allocator_provider(Alloc&& alloc, decltype((new storage_policy(std::declval<Alloc>())), int()) = 0) : storage_policy(std::forward<Alloc>(alloc))
        {
        }
    };
}
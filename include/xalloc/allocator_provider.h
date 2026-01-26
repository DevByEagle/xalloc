#pragma once

#include <new>

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

        allocator_provider(allocator_provider&& other) noexcept : storage_policy(std::move(other)) {}

        allocator_provider(const allocator_provider&) = default;
        allocator_provider& operator=(const allocator_provider&) = default;
    };

    /** @brief
     *
     *  @tparam RawAllocator The underlying allocator type to store.
     * 
     *  @sa @ref allocator_provider
     * 
     *  @ingroup storage
     */
    template <class RawAllocator>
    using allocator_ptr = allocator_provider<RawAllocator>;
}
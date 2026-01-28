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

        allocator_provider(allocator_provider&& other) noexcept : storage_policy(std::move(other))
        {
        }

        allocator_provider(const allocator_provider&) = default;
        allocator_provider& operator=(const allocator_provider&) = default;
    };

    template <class RawAllocator>
    class reference_storage
    {
    public:
        using allocator_type = typename allocator_traits<RawAllocator>::allocator_type;

        reference_storage() noexcept = default;

    protected:
        ~reference_storage() noexcept = default;
    };

    /** @brief
     *
     *  @tparam RawAllocator The underlying allocator type to store.
     * 
     *  @sa @ref allocator_provider
     *  @sa @ref reference_storage
     * 
     *  @ingroup storage
     */
    template <class RawAllocator>
    using allocator_ptr = allocator_provider<reference_storage<RawAllocator>>;
}
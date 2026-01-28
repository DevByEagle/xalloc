#pragma once

#include <type_traits>

#include "allocator_traits.h"
#include "error.h"

namespace xalloc
{
    struct memory_block
    {
        void* memory;
        size_t size;

        memory_block() noexcept : memory_block(nullptr, size_t(0)) {}

        memory_block(void* mem, size_t s) noexcept : memory(mem), size(s) {}

        bool contains(const void* address) const noexcept { return address >= memory && address < static_cast<const char*>(memory) + size; }
    };

    template <class BlockAllocator>
    class memory_arena : BlockAllocator
    {
    public:
        using allocator_type = BlockAllocator;

        ~memory_arena() noexcept
        {
        }

        allocator_type& get_allocator() noexcept
        {
            return *this;
        }
    };
}
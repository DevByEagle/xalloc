#ifndef XALLOC_MEMORY_ARENA_H_
#define XALLOC_MEMORY_ARENA_H_

#include <type_traits>

#include "default_allocator.h"

namespace xalloc {
    struct memory_block
    {
        void* memory;
        std::size_t size;
        
        memory_block() noexcept : memory_block(nullptr, std::size_t(0)) {}

        memory_block(void* mem, std::size_t s) noexcept : memory(mem), size(s) {}

        /// @returns Whether or not a pointer is inside the memory.
        bool contains(const void* address) const noexcept
        {
            auto mem  = static_cast<const char*>(memory);
                auto addr = static_cast<const char*>(address);
                return addr >= mem && addr < mem + size;
        }
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

#endif 
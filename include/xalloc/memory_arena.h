#ifndef XALLOC_MEMORY_ARENA_H_
#define XALLOC_MEMORY_ARENA_H_

#include <type_traits>

#include "config.h"
#include "default_allocator.h"

namespace xalloc
{
    struct memory_block
    {
        void* memory;
        std::size_t size;

        memory_block() noexcept = default;

        memory_block(void* mem, std::size_t s) noexcept : memory(mem), size(s) {}
    };

    namespace internal
    {
    }

    template <class BlockAllocator>
    class memory_arena : BlockAllocator
    {
    public:
        using allocator_type = BlockAllocator;
        
        memory_arena() noexcept = default;

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
#ifndef XALLOC_HEAP_ALLOCATOR_H_
#define XALLOC_HEAP_ALLOCATOR_H_

#include <cstdint>

#include "config.h"

namespace xalloc
{
    void* heap_alloc(std::size_t size) noexcept;
    void heap_dealloc(void* ptr, std::size_t size) noexcept;

    namespace internal
    {
        struct heap_allocator_impl
        {
            static void* allocate(std::size_t size, std::size_t) noexcept
            {
                return heap_alloc(size);
            }

            static void deallocate(void* ptr, std::size_t size, std::size_t) noexcept
            {
                heap_dealloc(ptr, size);
            } 
        };
    }

    using heap_allocator = internal::heap_allocator_impl;
}

#endif
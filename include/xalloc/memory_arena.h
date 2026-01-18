#pragma once

#include "xalloc.h"

#include "allocator_traits.h"

namespace xalloc
{
    struct memory_block
    {
        void* memory;
        size_t size;

        memory_block() noexcept : memory_block(nullptr, size_t(0)) {}

        memory_block(void* mem, size_t s) noexcept : memory(mem), size(s) {}
    };
}
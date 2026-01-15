#pragma once

#include "config.h"

#include <cstddef>

struct memory_block;

namespace xalloc
{
    /** @brief
     * 
     *  @return
     * 
     *  @sa @ref xalloc::MemAlloc
     * 
     *  @since Added in version 1.0.
     * 
     *  @ingroup allocator
     */
    void* MemAlloc(std::size_t size);
    void MemFree(void* ptr);
    // std::size_t GetAllocatedSize();
}

struct memory_block
{
};
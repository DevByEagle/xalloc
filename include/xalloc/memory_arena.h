#pragma once

#include "allocator_traits.h"
#include "error.h"

namespace xalloc
{
    struct memory_block
    {
        void* memory;
        size_t size;

        memory_block() : memory_block(nullptr, size_t(0)) {}
        memory_block(void* mem, size_t s) : memory(mem), size(s) {}
        
        bool contains(const void* address) const 
        { 
            return address >= memory && address < static_cast<char*>(memory) + size; 
        }
    };
}
#pragma once

#include <type_traits>

#include "config.h"

namespace xalloc
{
    struct memory_block
    {
    };

    template <class BlockAllocator>
    class memory_arena : BlockAllocator
    {
    };
}
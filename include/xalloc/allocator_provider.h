#pragma once

#include <new>
#include <type_traits>

#include "allocator_traits.h"

namespace xalloc
{
    template <class StoragePolicy>
    class allocator_provider : StoragePolicy
    {

    };

    template <class RawAllocator>
    using allocator_ptr = void;
}
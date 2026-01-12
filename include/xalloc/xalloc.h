#ifndef XALLOC_H_
#define XALLOC_H_

#include <list>

#include "std_allocator.h"

namespace xalloc {
    template <typename T, class RawAllocator>
    using list = std::list<T, std_allocator<T, RawAllocator>>;
}

#endif
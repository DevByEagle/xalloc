#include <iostream>

#define XALLOC_ENABLE_ADVANCED_FEATURES
#include <xalloc/xalloc.h>
#include <xalloc/memory_arena.h>

int main()
{
    int* arr = (int*)xalloc::MemAlloc(4 * sizeof(int));
    xalloc::allocator_traits<void> traits;
    xalloc::memory_block block;
    std::cout << block.contains(arr);
    return 0;
}
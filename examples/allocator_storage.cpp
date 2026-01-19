#include <iostream>

#define XALLOC_ENABLE_ADVANCED_FEATURES
#include <xalloc/xalloc.h>
#include <xalloc/std_allocator.h>

int main()
{
    xalloc::std_allocator<int, int> allocator;
    xalloc::std_allocator<void, void> b;
    if (allocator == b)
    {

    }
    return 0;
}
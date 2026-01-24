#include <iostream>

#define XALLOC_ENABLE_ADVANCED_FEATURES
#include <xalloc/xalloc.h>

int main()
{
    throw xalloc::out_of_memory();
    return 0;
}
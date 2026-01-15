#include <iostream>

#define XALLOC_ENABLE_ADVANCED_FEATURES
#include <xalloc/xalloc.h>

int main()
{
    int* arr = static_cast<int*>(xalloc::MemAlloc(4 * sizeof(int)));
    return 0;
}
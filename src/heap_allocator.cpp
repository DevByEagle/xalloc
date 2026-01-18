#include "xalloc.h"

#ifdef _WIN32
#include <malloc.h>
#include <windows.h>

void* xalloc::MemAlloc(std::size_t size)
{
    return nullptr;
}

void xalloc::MemFree(void* ptr)
{
    (void)ptr;
}
#elif XALLOC_HOSTED_IMPLEMENTATION
void* xalloc::MemAlloc(size_t size)
{
    (void)size;
    return nullptr;
}

void xalloc::MemFree(void* ptr)
{
    (void)ptr;
}
#else
#endif
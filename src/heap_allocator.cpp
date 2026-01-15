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
}
#else
void* xalloc::MemAlloc(std::size_t size)
{
    (void)size;
    return nullptr;
}

void xalloc::MemFree(void* ptr)
{
    (void)ptr;
}
#endif
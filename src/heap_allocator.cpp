#include "heap_allocator.h"

using namespace xalloc;

#if defined(_WIN32) || defined(_WIN64)
#if defined(_MSC_VER)
    #include <Windows.h>
#else
    #include <windows.h>
#endif
#include <malloc.h>

namespace 
{
    HANDLE get_process_heap() noexcept
    {
        static auto heap = GetProcessHeap();
        return heap;
    }
}

void* xalloc::heap_alloc(std::size_t size) noexcept
{
    return HeapAlloc(get_process_heap(), 0, size);
}

void xalloc::heap_dealloc(void* ptr, std::size_t) noexcept
{
    HeapFree(get_process_heap(), 0, ptr);
}
#elif XALLOC_HOSTED_IMPLEMENTATION
#include <cstdlib>
#include <memory>

void* xalloc::heap_alloc(std::size_t size) noexcept
{
    return std::malloc(size);
}

void xalloc::heap_dealloc(void* ptr, std::size_t) noexcept
{
    std::free(ptr);
}
#endif
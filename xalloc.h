#ifndef XALLOC_H
#define XALLOC_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#if defined(_WIN32) || defined(_WIN64)
    #if defined(_MSC_VER)
         #include <Windows.h>
    #else
        #include <windows.h>
    #endif
#else
    #include <unistd.h>
#endif

struct XBlock {
    size_t size;
    struct XBlock* next;
};

static struct XBlock* freelist = NULL;
static bool xallocDebugEnable;

void* xalloc(size_t size) {
    if (freelist == NULL) {
        #if defined(_WIN32) || defined(_WIN64)
        void* block = VirtualAlloc(NULL, size + sizeof(struct XBlock), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
        #else
        void* block = sbrk(size + sizeof(struct XBlock));
        #endif

        assert(block != NULL);  // Ensure memory allocation succeeded

        struct XBlock* memoryBlock = (struct XBlock*) block;
        memoryBlock->size = size;
        memoryBlock->next = NULL;

        return (void*)(memoryBlock + 1);
    }

    struct XBlock* current = freelist;
    freelist = freelist->next;
    current->size = size;

    return (void*)(current + 1);
}

void xfree(void* ptr) {
    struct XBlock* block = (struct XBlock*) ptr - 1;

    #if defined(_WIN32) || defined(_WIN64)
    VirtualFree(block, 0, MEM_RELEASE);
    #else
    block->next = freelist;
    freelist = block;
    #endif
}

void* xrealloc(void* ptr, size_t newsize) {
    if (ptr == NULL) return xalloc(newsize);

    struct XBlock* block = (struct XBlock*) ptr - 1;

    if (block->size >= newsize) return ptr; // No need to resize

    void* newPtr = xalloc(newsize);
    assert(newPtr != NULL);  // Ensure new memory allocation succeeded

    memcpy(newPtr, ptr, block->size);
    xfree(ptr);

    return newPtr;
}

// Debug Tools
static void xalloc_print(const char* str) {
    #if defined(_WIN32) || defined(_WIN64)
    OutputDebugStringA(str);  // Windows output function
    #else
    write(1, str, strlen(str));  // Unix-like systems (Linux/macOS)
    #endif
}

void xalloc_print_stats(void) {
    if (!xallocDebugEnable) return;

    size_t total_free_memory = 0;
    size_t total_free_blocks = 0;
    struct XBlock* current = freelist;

    while (current != NULL) {
        total_free_blocks++;
        total_free_memory += current->size;
        current = current->next;
    }

    // Printing the stats
    char buffer[256];
    int len = snprintf(buffer, sizeof(buffer),
        "Memory Allocator Stats:\n  Total Free Memory: %zu bytes\n  Total Free Blocks: %zu\n",
        total_free_memory, total_free_blocks);

    if (len > 0) {
        xalloc_print(buffer);
    }
}

#endif // XALLOC_H
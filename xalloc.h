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
static void xalloc_log_to_file(void) {
    assert(false && "xalloc_log_to_file is not implemented");
}

void xalloc_print_stats(void) {
    assert(false && "xalloc_print_stats is not implemented");
}

#endif // XALLOC_H
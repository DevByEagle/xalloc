#ifndef XALLOC_H_
#define XALLOC_H_

#include <stddef.h>
#include <stdint.h>
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

static struct XBlock* free_list = NULL;

void* xalloc(size_t size) {
    assert(size > 0);
    
    if (free_list == NULL) {
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

    struct XBlock* current = free_list;
    free_list = free_list->next;
    current->size = size;

    return (void*)(current + 1);
}

void xfree(void* ptr) {
    assert(ptr != NULL);  // Ensure that the pointer is not NULL

    struct XBlock* block = (struct XBlock*) ptr - 1;

    // Ensure the block size is valid
    assert(block->size > 0);

    #if defined(_WIN32) || defined(_WIN64)
    VirtualFree(block, 0, MEM_RELEASE);
    #else
    block->next = free_list;
    free_list = block;
    #endif
}

void* xrealloc(void* ptr, size_t new_size) {
    assert(new_size > 0);  // Ensure that size is greater than 0

    if (ptr == NULL) {
        return xalloc(new_size);
    }

    struct XBlock* block = (struct XBlock*) ptr - 1;
    assert(block->size > 0);  // Ensure the block size is valid

    if (block->size >= new_size) return ptr; // No need to resize

    void* newPtr = xalloc(new_size);
    assert(newPtr != NULL);  // Ensure new memory allocation succeeded

    memcpy(newPtr, ptr, block->size);
    xfree(ptr);

    return newPtr;
}

#endif
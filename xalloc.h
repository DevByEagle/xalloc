#ifndef XALLOC_H_
#define XALLOC_H_

#include <stddef.h>
#include <stdint.h>
#include <string.h>

#define ALIGNMENT 16
#define MEMORY_SIZE 1024 * 1024 // 1 MB memory pool size

typedef struct XBlock {
    size_t size;
    struct XBlock* next;
} XBlock;

static uint8_t memory_pool[MEMORY_SIZE];
static XBlock* free_list = NULL;

static inline size_t align(size_t size) {
    return (size + ALIGNMENT - 1) & ~(ALIGNMENT - 1);
}

static void init_allocator() {
    if (free_list == NULL) {
        free_list = (XBlock*) memory_pool;
        free_list->size = MEMORY_SIZE - sizeof(XBlock);
        free_list->next = NULL;
    }
}

void* xalloc(size_t size) {
    init_allocator();
    
    size = align(size);
    XBlock* prev = NULL;
    XBlock* curr = free_list;

    while (curr) {
        if (curr->size >= size) {
            if (curr->size > size + sizeof(XBlock)) {
                XBlock* new_block = (XBlock*) ((uint8_t*) curr + sizeof(XBlock) + size);
                new_block->size = curr->size - size - sizeof(XBlock);
                new_block->next = curr->next;
                curr->size = size;
                curr->next = new_block;
            }

            if (prev) {
                prev->next = curr->next;
            } else {
                free_list = curr->next;
            }

            return (void*) (curr + 1);
        }

        prev = curr;
        curr = curr->next;
    }

    return NULL; // Not enough memory available
}

void* xrealloc(void* ptr, size_t new_size) {
    if (!ptr) return xalloc(new_size);

    XBlock* old_block = (XBlock*) ptr - 1;
    
    if (new_size <= old_block->size) {
        return ptr;
    }

    void* new_ptr = xalloc(new_size);
    if (!new_ptr) return NULL; // Allocation failed

    memcpy(new_ptr, ptr, old_block->size);

    xfree(ptr);

    return new_ptr;
}

void xfree(void* ptr) {
    if (!ptr) return; // Null pointer check

    XBlock* block = (XBlock*) ptr - 1;

    block->next = free_list;
    free_list = block;
}

#endif
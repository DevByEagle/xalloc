#ifndef XALLOC_H
#define XALLOC_H

#include <stddef.h>
#include <stdint.h>

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
    free_list = (XBlock*)memory_pool;
    free_list->size = MEMORY_SIZE - sizeof(XBlock);
    free_list->next = NULL;
}

void* xalloc(size_t size) {
    init_allocator();

    size = align(size);
    XBlock* prev = NULL;
    XBlock* current = free_list;

    while (current) {
        if (current->size >= size) {
            if (current->size > size + sizeof(XBlock)) {
                XBlock* new_block = (XBlock*)((uint8_t*)current + sizeof(XBlock) + size);
                new_block->size = current->size - size - sizeof(XBlock);
                new_block->next = current->next;
                current->size = size;
                current->next = new_block;
            }

            if (prev) {
                prev->next = current->next;
            } else {
                free_list = current->next;
            }

            return (void*)(current + 1);
        }

        prev = current;
        current = current->next;
    }

    return NULL; // Not enough memory available
}

void xfree(void* ptr) {
    XBlock* block = (XBlock*) ptr - 1; // Get the Block header

    // Add the block back to the free list
    block->next = free_list;
    free_list = block;
}

#endif
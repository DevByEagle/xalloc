#ifndef XALLOC_H_
#define XALLOC_H_

#include <stddef.h>
#include <stdint.h>

#define ALIGNMENT 16
#define MEMORY_SIZE 1024 * 1024 // 1 MB memory pool size

// Block structure for free list
typedef struct XBlock {
    size_t size;
    struct XBlock* next;
} XBlock;

static uint8_t memory_pool[MEMORY_SIZE];
static XBlock* free_list = NULL;

// Align the memory size to the nearest multiple of ALIGNMENT
static inline size_t align(size_t size) {
    return (size + ALIGNMENT - 1) & ~(ALIGNMENT - 1);
}

// Initialize the memory pool and free list
static void init_allocator() {
    if (free_list == NULL) {
        free_list = (XBlock*) memory_pool;
        free_list->size = MEMORY_SIZE - sizeof(XBlock);
        free_list->next = NULL;
    }
}

// Allocate memory from the pool
void* xalloc(size_t size) {
    init_allocator();
    
    size = align(size);
    XBlock* prev = NULL;
    XBlock* curr = free_list;

    while (curr) {
        if (curr->size >= size) {
            // If the block is large enough, split it
            if (curr->size > size + sizeof(XBlock)) {
                XBlock* new_block = (XBlock*) ((uint8_t*) curr + sizeof(XBlock) + size);
                new_block->size = curr->size - size - sizeof(XBlock);
                new_block->next = curr->next;
                curr->size = size;
                curr->next = new_block;
            }

            // Remove the block from the free list
            if (prev) {
                prev->next = curr->next;
            } else {
                free_list = curr->next;
            }

            // Return pointer to the memory after the block header
            return (void*) (curr + 1);
        }

        prev = curr;
        curr = curr->next;
    }

    return NULL; // Not enough memory available
}

// Free memory back to the pool
void xfree(void* ptr) {
    if (!ptr) return; // Null pointer check

    XBlock* block = (XBlock*) ptr - 1; // Get the Block header

    // Add the block back to the free list
    block->next = free_list;
    free_list = block;
}

#endif
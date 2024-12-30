#ifndef XALLOC_H_
#define XALLOC_H_

#ifndef MEMORY_SIZE
#error "You must define MEMORY_SIZE, e.g. #define MEMORY_SIZE 1024"
#endif

#define ALIGNMENT 16

#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

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
        free_list = (XBlock*)memory_pool;
        free_list->size = MEMORY_SIZE - sizeof(XBlock);
        free_list->next = NULL;
    }
}

void* xalloc(size_t size) {
    init_allocator();

    if (size > MEMORY_SIZE - sizeof(XBlock)) {
        assert(false && "Requested memory size exceeds available memory");
        return NULL;
    }
    
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

    assert(false && "Not enough memory available");
    return NULL;
}

void xfree(void* ptr) {
    if (!ptr) return; // Null pointer check

    XBlock* block = (XBlock*) ptr - 1;

    block->next = free_list;
    free_list = block;
}

#endif

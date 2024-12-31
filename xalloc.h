#ifndef XALLOC_H_
#define XALLOC_H_

#ifndef MEMORY_SIZE
#error "You must define MEMORY_SIZE, e.g. #define MEMORY_SIZE 1024"
#endif

#include <stddef.h>
#include <stdint.h>
#include <stddef.h>
//#include <assert.h>
//#include <stdbool.h>

#define ALIGNMENT 16

struct XBlock {
    size_t size;
    struct XBlock* next;
};

static uint8_t memory_pool[MEMORY_SIZE];
static struct XBlock* free_list = NULL;

static inline size_t align(size_t size) {
    return (size + ALIGNMENT - 1) & ~(ALIGNMENT - 1);
}

static void init_allocator() {
    if (free_list == NULL) {
        free_list = (struct XBlock*)memory_pool;
        free_list->size = MEMORY_SIZE - sizeof(struct XBlock);
        free_list->next = NULL;
    }
}

void* xalloc(size_t size) {
    init_allocator();
    
    size = align(size);
    struct XBlock* prev = NULL;
    struct XBlock* curr = free_list;

    while (curr) {
        if (curr->size >= size) {
            if (curr->size > size + sizeof(struct XBlock)) {
                struct XBlock* new_block = (struct XBlock*) ((uint8_t*) curr + sizeof(struct XBlock) + size);
                new_block->size = curr->size - size - sizeof(struct XBlock);
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

    return NULL;
}

void xfree(void* ptr) {
    if (!ptr) return;

    struct XBlock* block = (struct XBlock*) ptr - 1;
 
    block->next = free_list;
    free_list = block;
}

#endif
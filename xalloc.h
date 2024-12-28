#ifndef XALLOC_H
#define XALLOC_H

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MEMORY_POOL_SIZE 1024 // Example size of the memory pool (1 KB)

static uint8_t memory_pool[MEMORY_POOL_SIZE];
static uint8_t allocation_map[MEMORY_POOL_SIZE / sizeof(void *)];

void *xalloc(size_t size)
{
    size_t blocks_needed = (size + sizeof(void *) - 1) / sizeof(void *); // Calculate how many blocks are needed

    for (size_t i = 0; i < MEMORY_POOL_SIZE / sizeof(void *); i++)
    {
        // Check if there is enough contiguous free space
        if (i + blocks_needed <= MEMORY_POOL_SIZE / sizeof(void *))
        {
            bool space_available = true;

            for (size_t j = 0; j < blocks_needed; j++)
            {
                if (allocation_map[i + j] != 0)
                {
                    space_available = false;
                    break;
                }
            }

            if (space_available)
            {
                // Mark the blocks as allocated
                for (size_t j = 0; j < blocks_needed; ++j)
                {
                    allocation_map[i + j] = 1;
                }

                return (void*)&memory_pool[i * sizeof(void*)];
            }
        }
    }

    // No suitable space found
    return NULL;
}

void xfree(void* ptr) {
    size_t block_index = ((unsigned char*)ptr - memory_pool) / sizeof(void*);

    // Free the allocated blocks by marking them as free
    allocation_map[block_index] = 0;
}

#endif // XALLOC_H
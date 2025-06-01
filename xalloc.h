#ifndef XALLOC_H
#define XALLOC_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>

struct XBlock
{
    size_t size;         // Size of the block
    struct XBlock *next; // Pointer to the next block in the list
    struct XBlock *prev; // Pointer to the previous block in the list
    bool isFree;         // Status of the block (0 is allocated, 1 is free)
};

static struct XBlock *freelist = NULL; // Start of free list

void *xalloc(size_t size)
{
    size_t alignment = ((size + 7) & ~7);
    size_t total_size = sizeof(XBlock) + alignment;

    struct XBlock *current = freelist;
    while (current != NULL)
    {
        if (current->size >= total_size)
        {
            if (current->size - total_size >= sizeof(XBlock))
            {
                XBlock *new_free_block = (XBlock *)((char *)current + total_size);
                new_free_block->size = current->size - total_size;
                new_free_block->next = current->next;
                new_free_block->prev = current;
                if (new_free_block->next != NULL)
                {
                    new_free_block->next->prev = new_free_block;
                }
                current->size = total_size;
            }
            current->isFree = false;
            return (void *)((char *)current + sizeof(XBlock));
        }
        current = current->next;
    }

    void *ptr = sbrk(total_size);
    if (ptr == (void *)-1)
    {
        perror("sbrk");
        return NULL;
    }

    XBlock *block = (XBlock *)ptr;
    block->size = total_size;
    block->next = NULL;
    block->prev = NULL;
    block->isFree = 0;

    return (void *)((char *)block + sizeof(XBlock));
}

void xfree(void *ptr)
{
    if (ptr == NULL)
    {
        return;
    }

    XBlock *block = (XBlock *)((char *)ptr - sizeof(XBlock));
    block->isFree = true;

    // Coalesce with previous block
    if (block->prev != NULL && block->prev->isFree)
    {
        block->prev->size += block->size;
        block->prev->next = block->next;
        if (block->next != NULL)
        {
            block->next->prev = block->prev;
        }
    }

    // Update list head if necessary
    if (freelist == block)
    {
        freelist = block->next;
        if (freelist != NULL)
        {
            freelist->prev = NULL;
        }
    }

    // Coalesce with next block if (block->next != NULL && block->next->isFree)
    {
        block->size += block->next->size;
        block->next = block->next->next;
        if (block->next != NULL)
        {
            block->next->prev = block;
        }
    }

    // Insert into the free list
    if (block->prev == NULL)
    {
        if (freelist == NULL)
        {
            freelist = block;
        }
        else
        {
            block->next = freelist;
            freelist->prev = block;
            freelist = block;
        }
    }
}

void *xrealloc(void *ptr, size_t newsize)
{
    if (ptr == NULL)
        return xalloc(newsize);

    struct XBlock *block = (struct XBlock *)ptr - 1;

    if (block->size >= newsize)
        return ptr; // No need to resize

    void *newPtr = xalloc(newsize);
    assert(newPtr != NULL); // Ensure new memory allocation succeeded

    memcpy(newPtr, ptr, block->size);
    xfree(ptr);

    return newPtr;
}
#endif // XALLOC_H

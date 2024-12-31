# Xalloc - A High-Performance Memory Allocator

`xalloc` is a custom memory allocator designed for high performance, low overhead, and flexibility in memory management for C and C++ projects. It is optimized to handle allocation and deallocation of memory efficiently, minimizing fragmentation, and improving runtime performance.

## Quick Start

Here’s how you can integrate `xalloc` into your project:


```c
#define MEMORY_SIZE 1024 * 512
#include "xalloc.h"
#include <stdio.h>

int main() {
    int* arr = (int*)xalloc(sizeof(int) * 10);
    if (arr == NULL) {
        fprintf(stderr, "Allocation failed\n");
        return 1;
    }

    // Use the memory...

    xfree(arr);
    
    return 0;
}
```
# Xalloc - A High-Performance Memory Allocator

`xalloc` is a custom memory allocator designed for high performance, low overhead, and flexibility in memory management for C and C++ projects. It is optimized to handle allocation and deallocation of memory efficiently, minimizing fragmentation, and improving runtime performance.

## Quick Start

Here’s how you can integrate `xalloc` into your project:

```c
#include "xalloc.h"

int main() {
    void* ptr = xalloc(24);
    assert(ptr != NULL && "Failed to allocate memory.");

    // Use the memory...

    xfree(ptr);
    return 0;
}
```
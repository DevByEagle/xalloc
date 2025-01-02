# Xalloc - A High-Performance Memory Allocator

`xalloc` is a custom memory allocator designed for high performance, low overhead, and flexibility in memory management for C and C++ projects. It is optimized to handle allocation and deallocation of memory efficiently, minimizing fragmentation, and improving runtime performance.

## Quick Start

Here’s how you can integrate `xalloc` into your project:

```c
#include "xalloc.h"

int main() {
    int* arr = (int*)xalloc(10 * sizeof(int));
    assert(arr != NULL);

    // Use the memory...

    xfree(arr);
    return 0;
}
```

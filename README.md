# Xalloc 

`xalloc` is a lightweight and efficient custom memory allocator designed to provide automatic memory management in C projects. It aims to offer control over memory allocation, deallocation, and handling without relying on standard library functions like `malloc` or `free`.

## Example

```c
#include <stdio.h>

#define MEMORY_SIZE 1024 * 1024 // You Need to define the memory size or else it while error.
#include "xalloc.h"

int main() {
    int* arr = (int*)xalloc(10 * sizeof(int));

    // Use the memory...

    xfree(arr);
    return 0;
}
```

# Xalloc 

`xalloc` is a lightweight and efficient custom memory allocator designed to provide automatic memory management in C projects. It aims to offer control over memory allocation, deallocation, and handling without relying on standard library functions like `malloc` or `free`.

## Example

> !NOTE
> 
> Do Not use the other function in xalloc besides `xalloc`, `xrealloc` and `xfree`. 

```c
#include "xalloc.h"

int main() {
    int* arr = (int*)xalloc(10 * sizeof(int));
    if (arr == NULL) {
        // Handle allocation failure
    }

    // Use the memory...

    xfree(arr);
    return 0;
}
```
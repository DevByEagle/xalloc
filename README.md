# Xalloc - A High-Performance Memory Allocator

`xalloc` is a custom memory allocator designed for high performance, low overhead, and flexibility in memory management for C and C++ projects. It is optimized to handle allocation and deallocation of memory efficiently, minimizing fragmentation, and improving runtime performance.

## API Reference

### Core Functions

```c
// Allocates a block of memory of the given size in bytes.
void* xalloc(size_t size);

// Frees the memory block pointed to by `ptr`.
void xfree(void* ptr);

// Resizes the memory block pointed to by `ptr` to the specified size.
void* xrealloc(void* ptr, size_t newsize);
```

<!-- ## Debugging Tools
`xalloc`  includes built-in support for detecting memory-related issues like memory leaks and invalid memory access. Use the following functions for debugging:

```c
// Prints memory allocation statistics, including memory usage and leaks.
void xalloc_print_stats(void);
``` -->
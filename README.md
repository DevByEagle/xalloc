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
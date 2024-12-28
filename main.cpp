#include <stdio.h>
#include "xalloc.h"

int main() {
    void* ptr1 = xalloc(sizeof(int));
    void* ptr2 = xalloc(200);
    void* ptr3 = xalloc(300);

    printf("Allocated memory blocks at: %p, %p, %p\n", ptr1, ptr2, ptr3);

    xfree(ptr1);
    xfree(ptr2);

    void* ptr4 = xalloc(300);
    printf("Allocated memory block at: %p\n", ptr4);

    xfree(ptr3);
    xfree(ptr4);

    return 0;
}
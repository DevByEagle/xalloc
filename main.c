#include <stdio.h>
#include "xalloc.h"

int main() {
    void* ptr1 = xalloc(512);
    void* ptr2 = xalloc(256);
    void* ptr3 = xalloc(128);

    printf("Allocated ptr1: %p (size: 512 bytes)\n", ptr1);
    printf("Allocated ptr2: %p (size: 256 bytes)\n", ptr2);
    printf("Allocated ptr3: %p (size: 128 bytes)\n", ptr3);

    xfree(ptr1);
    xfree(ptr2);
    xfree(ptr3);

    printf("%p\n", ptr1);

    return 0;
}

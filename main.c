#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#define MEMORY_SIZE 1024 * 512
#include "xalloc.h"

int main() {
    int* arr = (int*)xalloc(sizeof(int) * 10);
    
    assert(arr != NULL && "Could Not allocate memory or arr");

    printf("arr: %p\n", arr);

    xfree(arr);

    return 0;
}
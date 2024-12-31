#include <stdio.h>

#define MEMORY_SIZE 1024 * 512
#include "xalloc.h"

int main() {
    int* arr = (int*)xalloc(sizeof(int) * 10);

    if (arr == NULL) {
        fprintf(stderr, "Failed to allocate memory for arr");
        return 1;
    }

    printf("%s\n", arr);

    xfree(arr);

    return 0;
}
#include <stdio.h>
#include <stdbool.h>
#include "xalloc.h"

int main(void) {
    int* arr = (int*)xalloc(5 * sizeof(int));
    if (arr == NULL) {
        assert(false && "Failed to allocate memory");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    arr = (int*)xrealloc(arr, 10 * sizeof(int));
    if (arr == NULL) {
        assert(false && "Failed to allocate memory");
        return 1;
    }

    for (int i = 5; i < 10; i++) {
        arr[i] = i + 1;
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    xfree(arr);

    return 0;
}
#include <iostream>

#define MEMORY_SIZE 1024 * 1024 * 1024 * 1024
#include "xalloc.h"

int main() {
    int* arr = (int*)xalloc(10 * sizeof(int));

    std::cout << *arr << std::endl;
    return 0;
}
#include <iostream>

#define MEMORY_SIZE 1024 * 512
#include "xalloc.h"

int main(void) {
    int* arr = (int*)xalloc(10 * sizeof(int));
    void* ptr = xalloc(25);

    std::cout << arr << std::endl;
    std::cout << ptr << std::endl;
}
#include <iostream>
#include "xalloc.h"

int main() {
    int* a = (int*)xalloc(sizeof(int));
    int* b = (int*)xalloc(sizeof(int));

    std::cout << a << std::endl;
    std::cout << b << std::endl;
}

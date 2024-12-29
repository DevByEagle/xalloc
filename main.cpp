#include <iostream>
#include "xalloc.h"

int main() {
    void* ptr1 = xalloc(26);

    std::cout << ptr1 << std::endl;

    xfree(ptr1);

    return 0;
}

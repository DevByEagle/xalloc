#include <iostream>
#include "xalloc.h"

int main() {
    void* ptr1 = xalloc(26);
    void* ptr2 = xalloc(sizeof(int));

    std::cout << ptr1 << std::endl;
    std::cout << ptr2 << std::endl;

    xfree(ptr1);
    xfree(ptr2);

    return 0;
}

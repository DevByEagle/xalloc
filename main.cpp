#include <iostream>
#include "xalloc.h"

int main() {
    int* a = (int*) xalloc(sizeof(int));
    if (a) {
        *a = 42; // Assign a value
        std::cout << "Allocated memory for 'a', value: " << *a << std::endl;
    } else {
        std::cerr << "Memory allocation failed for 'a'" << std::endl; 
        printf("Memory allocation failed for 'a'\n");
    }

}

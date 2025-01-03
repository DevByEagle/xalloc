#include <stdio.h>
#include "xalloc.h"


int main() {
    xallocDebugEnable = true;

    void* ptr = xalloc(128);
    xalloc_print_stats();

    xallocDebugEnable = false;
    xalloc_print_stats();

    xfree(ptr);
    return 0;
}
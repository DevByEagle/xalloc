#include <iostream>

#include <xalloc/xalloc.h>
#include <xalloc/memory_arena.h>

using namespace xalloc::units;

int main() {
    // using namespace xalloc::units;

    auto v = 45KiB;
    std::cout << v<< std::endl;

    xalloc::memory_arena<xalloc::memory_block> arena;
    return 0;
}
#include <iostream>

#define XALLOC_ENABLE_ADVANCED_FEATURES
#include <xalloc/xalloc.h>
// #include <xalloc/allocator_provider.h>

struct MyStruct
{
    int x, y;
    using allocator_type = MyStruct;
    constexpr MyStruct() : x(0), y(0) {}
    constexpr MyStruct(int _x, int _y) : x(_x), y(_y) {}
};

int main()
{
    return 0;
}
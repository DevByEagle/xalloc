#include <algorithm>
#include <iostream>
#include <iterator>

#define XALLOC_ENABLE_ADVANCED_FEATURES
#include <xalloc/xalloc.h>
#include <xalloc/allocator_provider.h>

struct MyStruct
{
    int x, y;
    using allocator_type = MyStruct;
    constexpr MyStruct() : x(0), y(0) {}
    constexpr MyStruct(int _x, int _y) : x(_x), y(_y) {}
};

int main()
{
    xalloc::allocator_ptr<MyStruct> allocator;
    return 0;
}
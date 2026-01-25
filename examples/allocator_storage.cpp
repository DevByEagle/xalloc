#include <iostream>
#include <memory>

#define XALLOC_ENABLE_ADVANCED_FEATURES
#include <xalloc/xalloc.h>

struct MyStruct
{
    int x, y;
    constexpr MyStruct() : x(0), y(0) {}
    MyStruct(int _x, int _y) : x(_x), y(_y) {}
    using allocator_type = MyStruct;
};


int main()
{
    // xalloc::allocator_ptr<MyStruct> alloc = xalloc::make_allocator<MyStruct>()
    return 0;
}
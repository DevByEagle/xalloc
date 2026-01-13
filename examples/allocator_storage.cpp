#include <iostream>
#include <new>

#include <xalloc/xalloc.h>
#include <xalloc/memory_arena.h>

struct MyStruct
{
    int x, y;
    MyStruct(int a, int b) : x(a), y(b) {}
    void print() const { std::cout << "x=" << x << ", y=" << y << "\n"; }
};

int main()
{
    return 0;
}
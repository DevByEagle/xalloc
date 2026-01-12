#include <iostream>
#include <new>

#include <xalloc/xalloc.h>

struct MyStruct
{
    int x, y;
    MyStruct(int a, int b) : x(a), y(b) {}
    void print() const { std::cout << "x=" << x << ", y=" << y << "\n"; }
};

int main()
{
    xalloc::list<int, void> list;
    list.push_back(3);

    for (auto e : list)
        std::cout << e << ' ';
    std::cout << '\n';
    return 0;
}
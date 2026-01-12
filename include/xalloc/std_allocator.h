#ifndef XALLOC_STD_ALLOCATOR_H_
#define XALLOC_STD_ALLOCATOR_H_

#include <type_traits>

namespace xalloc
{
    template <typename T, class RawAllocator>
    class std_allocator
    {
    public:
        template <typename U, typename... Args>
        void construct(U* p, Args&&... args)
        {
            void* mem = p;
            ::new (mem) U(std::forward<Args>(args)...);
        }

        template <typename U>
        void destroy(U* p) noexcept
        {
            (void)p;
            p->~U();
        }
    };
}

#endif
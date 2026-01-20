#pragma once

#include <new>

namespace xalloc
{
    class out_of_memory : public std::bad_alloc
    {
    public:
        const char* what() const noexcept override;
    };
}
#pragma once

#include <new>

namespace xalloc
{
    /** @brief Exception thrown when a low-level allocator has run out of memory.
     *
     *  @note
     *  This can occur if an underlying allocation function such as
     *  @c std::malloc() runs out of available memory.
     * 
     *  @since Added in version 1.0.
     * 
     *  @ingroup core
     */
    class out_of_memory : public std::bad_alloc
    {
    public:
        const char* what() const noexcept override;
    };
}
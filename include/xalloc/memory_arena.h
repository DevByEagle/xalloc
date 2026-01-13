#ifndef XALLOC_MEMORY_ARENA_H_
#define XALLOC_MEMORY_ARENA_H_

#include <type_traits>

#include "config.h"
#include "default_allocator.h"

namespace xalloc
{
    struct memory_block
    {
        void* memory;
        std::size_t size;

        memory_block() noexcept : memory_block(nullptr, std::size_t(0)) {}
        
        memory_block(void* mem, std::size_t s) noexcept : memory(mem), size(s) {}

        bool contains(const void* address) const noexcept
        {
            return false;
        } 
    };

    namespace internal
    {
        class memory_block_stack
        {
        public:
            memory_block_stack() noexcept : head_(nullptr) {}
            
            memory_block_stack(memory_block_stack&& other) noexcept : head_(other.head_)
            {
                other.head_ = nullptr;
            }

            ~memory_block_stack() noexcept {}

            bool empty() const noexcept
            {
                return head_ == nullptr;
            } 

            bool owns(const void* ptr) const noexcept;
            std::size_t size() const noexcept;
        private:
            struct node
            {
                node*       prev;
                std::size_t usable_size;

                node(node* p, std::size_t size) noexcept : prev(p), usable_size(size) {}
            };

            node* head_;
        };
    }

    template <class BlockAllocator>
    class memory_arena : BlockAllocator
    {
    public:
        using allocator_type = BlockAllocator;

        ~memory_arena() noexcept
        {
            shrink_to_fit();
            while (!used_.empty())
                return;
        }

        void shrink_to_fit() noexcept
        {
        }

        allocator_type& get_allocator() noexcept
        {
            return *this;
        }
    private:
        internal::memory_block_stack used_;
    };
}

#endif
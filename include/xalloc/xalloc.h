#pragma once

#include "config.h"

#include <stddef.h>

namespace xalloc
{
    void* MemAlloc(size_t size);
    void  MemFree(void* ptr);
}
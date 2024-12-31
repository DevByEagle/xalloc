#include <iostream>
#include <windows.h>
#include <chrono>

//#define MEMORY_SIZE 1024
//#include "xalloc.h"
#include <stdlib.h>

int main() {
    const int numAllocations = 1000000; // Number of allocations to test
    const size_t allocSize = 64;        // Size of each allocation (in bytes)

    // Time allocation performance
    LARGE_INTEGER startTime, endTime;
    QueryPerformanceCounter(&startTime);

    for (int i = 0; i < numAllocations; ++i) {
        void* ptr = malloc(allocSize);
        free(ptr);  // Deallocate immediately
    }

    QueryPerformanceCounter(&endTime);
    
    // Calculate the elapsed time in milliseconds
    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);
    double elapsedTime = double(endTime.QuadPart - startTime.QuadPart) / frequency.QuadPart * 1000.0;
    std::cout << "Time taken for " << numAllocations << " allocations and deallocations: "
              << elapsedTime << " ms\n";
    return 0;
}

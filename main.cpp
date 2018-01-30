#include <iostream>
#include "PageFrameAllocator.h"

// Lab3 Robert Zachrich / James Shannon

int main() {
    std::vector<uint32_t > pageFrames;
    PageFrameAllocator page(10);
    page.Allocate(5, pageFrames);
    page.Deallocate(3, pageFrames);


    return 0;
}

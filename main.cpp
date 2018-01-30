#include <iostream>
#include "PageFrameAllocator.h"

// Lab3 Robert Zachrich / James Shannon

int main() {
    std::vector<uint32_t > pageFrames;
    PageFrameAllocator page(10);
    page.Allocate(2, pageFrames);
    page.Deallocate(1, pageFrames);


    return 0;
}

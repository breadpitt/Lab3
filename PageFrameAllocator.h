//
// Created by jasha on 1/26/2018.
//

#ifndef OSLAB3_PAGEFRAMEALLOCATOR_H
#define OSLAB3_PAGEFRAMEALLOCATOR_H


#include <iostream>
#include <vector>

class PageFrameAllocator {
    PageFrameAllocator(uint32_t num_page_frames){
        // do stuff
    }

private:
    std::vector<uint8_t> memory; // Byte array containing page frames to be managed
    uint8_t page_frames_total; // Count of total number of page frames in memory
    uint32_t page_frames_free; // Current number of free page frames
    uint32_t free_list_head; // Page frame number of first page frame in the free list (0xFFFFFFFF if list is empty
};


#endif //OSLAB3_PAGEFRAMEALLOCATOR_H

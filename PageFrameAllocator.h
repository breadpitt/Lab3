//
// Created by jasha on 1/26/2018.
//

#ifndef OSLAB3_PAGEFRAMEALLOCATOR_H
#define OSLAB3_PAGEFRAMEALLOCATOR_H


#include <iostream>
#include <string>
#include <vector>

class PageFrameAllocator {
public:

    // I copied a lot from the lab 2 file as a outline of what to do

    // Constructor, open file
    PageFrameAllocator(uint32_t num_page_frames_);
    // Destructor, close file
   // virtual ~PageFrameAllocator(void);

    // Other Constructors

   // PageFrameAllocator(uint32_t num_page_frames) = delete;
    bool Allocate(uint32_t count, std::vector<uint32_t> &page_frames);
    bool Deallocate(uint32_t count, std::vector<uint32_t> &page_frames);


    // Reads and process info from file
    void Execute(void);

private:
    // All the vectors
    std::vector<uint8_t> memory; // Byte array containing page frames to be managed
    std::vector<uint32_t> page_frames;
    int memory_size; // Number of pages * 4096 (0x1000)
    uint32_t num_page_frames;
    uint32_t page_frames_total; // Count of total number of page frames in memory
    uint32_t page_frames_free; // Current number of free page frames
    uint32_t free_list_head; // Page frame number of first page frame in the free list (0xFFFFFFFF if list is empty
};


#endif //OSLAB3_PAGEFRAMEALLOCATOR_H

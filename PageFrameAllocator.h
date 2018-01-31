//
// Created by jasha on 1/26/2018.
//

#ifndef OSLAB3_PAGEFRAMEALLOCATOR_H
#define OSLAB3_PAGEFRAMEALLOCATOR_H


#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class PageFrameAllocator {
public:

    PageFrameAllocator(int num_page_frames);
    ~PageFrameAllocator(){};

    // Rule of Five
        // think this is right? you should check
    PageFrameAllocator(PageFrameAllocator &orig) = delete; // copy
    PageFrameAllocator(PageFrameAllocator &&orig) = delete; // move
    PageFrameAllocator operator=(PageFrameAllocator &orig) = delete; // copy assignment? Forgot what its called
    PageFrameAllocator operator=(PageFrameAllocator &&orig) = delete; // move ^ same...

    // Allocation
    bool Allocate(uint32_t count, std::vector<uint32_t> &page_frames);
    bool Deallocate(uint32_t count, std::vector<uint32_t> &page_frames);

    // Assorted
    void Print(std::ofstream &inFile);
    void Read(std::string line, std::vector<uint16_t> line_values);


private:
    // set everything at start = 0
    std::fstream inputFile;
    std::vector<uint32_t> memory; // Byte array containing page frames to be managed
    int memory_size = 0; // Number of pages * 4096 (0x1000)
    std::vector<uint32_t> page_frames;
    uint32_t num_page_frames = 0;
    uint32_t index = 0;
    uint32_t index2 = 0;

    uint32_t page_frames_total = 0; // Count of total number of page frames in memory
    uint32_t page_frames_free = 0; // Current number of free page frames
    uint32_t free_list_head = 0; // Page frame number of first page frame in the free list

    // Out put stuff
    std::string line;
    std::vector<uint16_t> line_values;
    int read = 0;
    int count = 0;
    int line_number = 0;
};


#endif //OSLAB3_PAGEFRAMEALLOCATOR_H

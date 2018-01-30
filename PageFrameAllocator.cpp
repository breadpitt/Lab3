//
// Created by jasha on 1/26/2018.
//

#include "PageFrameAllocator.h"
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <sstream>

// x01000 bytes for page frame size
// first 4 bytes point to next page... 0xFFFFFFFF end pointer


PageFrameAllocator::PageFrameAllocator(uint32_t num_page_frames_) {

    uint32_t index = 0;
    memory.resize(num_page_frames_ * 4096);
    page_frames_total = memory.size() / 4096;
    //std::cout << memory.size() << "\n" << page_frames_total << "\n";
    page_frames_free = memory.size();

    // First four bytes of each page will point to the next page
    for (int i = 0; i < memory.size(); i += 4096){
        index += 4096;
        memory[i] = index;
    }
    num_page_frames_ = page_frames_total;
    std::cout <<  memory[4096] << "\n";
}


bool PageFrameAllocator::Allocate(uint32_t count, std::vector<uint32_t> &page_frames) {
    // takes number of pages to allocate from free list
    // push number of all allocated pages on the back of the vector page_frames
    // if num free pages is less than count then no allocation, return false
    // otherwise return true


    if (count > num_page_frames) {
            std::cout << "F 0\n";
            return 1;
        } else {
            std::cout << "T ";
        // Needs to be reworked
            for (uint32_t i = 0; i < count; i++) {
                page_frames.push_back(i);
                std::cout << page_frames[i] << " ";
            }
        std::cout << "\n";
        free_list_head = count*4096; // Page frame number of the first free list page frame in the free list
        page_frames_free = page_frames_free - count*4096;
        std::cout << page_frames_free << "\n";
        num_page_frames = num_page_frames - count;

            return 0;
        }
}


bool PageFrameAllocator::Deallocate(uint32_t count, std::vector<uint32_t> &page_frames) {
    // return last count page from vector page_frames to free list
    // numbers popped from back of page_frame vector as returned
    // true is count <= page_frames.size()
    // otherwise false, dont free anything

    if (count < page_frames.size()) {
        std::cout << "T ";
        for (uint32_t i = 0; i < count; i++) {
            page_frames.pop_back();
        }

        for (uint32_t i = 0; i < page_frames.size(); i++) {
            std::cout << page_frames[i] << " ";
        }
        std::cout << "\n";
        page_frames_free = page_frames_free + count*4096;
        num_page_frames = num_page_frames + count;
        std::cout << page_frames_free << "\n";
        return 0;
    } else {
        std::cout << "F 0\n";
    }
}


//Accessing Data Members
//All data member of the class must be private. You should supply public member
// functions to return values needed by users of this class
// For example, to access the current number of free page frames, in the .h file you could
// define the public class member function
//uint32_t get_page_frames_free() const { return page_frames_free; }
// move and copy not allowed


void PageFrameAllocator::Execute(void) {
    // one line at a time
    // read in first value on each line, count (hex) of pages to allocate or deallocate
    // 1 to allocate page frames
    // second value
    // 0 to deallocate
    // second value
    // 2 to print contents of the free list

    // output
    // wire line output preceded by ">"
    // after each allo / deallo write a line "S FC"
    // S value print "T" true if allocate visa vera
    // FC hex value of pages after allo
    // S = 2, two spaces, hex num pages in free list
}